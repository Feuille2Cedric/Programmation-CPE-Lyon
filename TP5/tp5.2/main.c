// main.c
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <stdlib.h>
#include "postfixe.h"
#include "evaluation_postfixe.h"
#include "variables.h"

// Convertit wchar_t* en char* pour la compatibilité avec d'autres fonctions
void wchar_to_char(const wchar_t *src, char *dest, size_t dest_size) {
    wcstombs(dest, src, dest_size);
    dest[dest_size - 1] = '\0'; // Assure la terminaison de la chaîne
}

// Initialisation de l'interpréteur
void init_interpreter() {
    setlocale(LC_ALL, "");  // Active la prise en charge de l'UTF-8
    init_variables();       // Initialise les variables
}

// Remplace toutes les occurrences d'une variable donnée dans une expression par une valeur fournie
void substitute_variable(wchar_t *expression, const wchar_t *variable, const wchar_t *value, wchar_t *result) {
    wchar_t *pos = expression;
    wchar_t *res_ptr = result;
    size_t var_len = wcslen(variable);
    while (*pos) {
        // Si le nom de la variable est trouvé dans l'expression, le remplacer par la valeur
        if (wcsncmp(pos, variable, var_len) == 0) {
            wcscpy(res_ptr, value); // Ajoute la valeur de substitution
            res_ptr += wcslen(value);
            pos += var_len;
        } else {
            *res_ptr++ = *pos++; // Ajoute le caractère original
        }
    }
    *res_ptr = '\0'; // Terminateur de chaîne
}

// Fonction principale pour gérer les expressions lambda
int handle_lambda_expression(wchar_t *input) {
    // Détection de l'expression lambda (commence par "(lambda ")
    wchar_t *lambda_start = wcsstr(input, L"(lambda ");
    if (!lambda_start) return 0;  // Pas d'expression lambda détectée, continuer le traitement

    // Extraction de la variable dans "(lambda x. expression)"
    wchar_t *var_pos = wcschr(lambda_start, L' ');
    if (!var_pos) return 0;
    wchar_t *dot_pos = wcschr(var_pos, L'.');
    if (!dot_pos) return 0;

    // Récupère le nom de la variable
    wchar_t variable[100];
    wcsncpy(variable, var_pos + 1, dot_pos - var_pos - 1);
    variable[dot_pos - var_pos - 1] = '\0';

    // Extraction de l'expression mathématique avec gestion des parenthèses
    wchar_t *expr_start = dot_pos + 1;
    wchar_t *expr_end = expr_start;
    int paren_count = 1; // Compteur de parenthèses pour repérer la bonne fermeture

    // Parcours pour trouver la fermeture correcte de l'expression
    while (*expr_end && paren_count > 0) {
        if (*expr_end == L'(') {
            paren_count++;
        } else if (*expr_end == L')') {
            paren_count--;
        }
        expr_end++;
    }

    // Si le nombre de parenthèses est incorrect, afficher une erreur
    if (paren_count != 0) {
        wprintf(L"Erreur : expression lambda mal formée\n");
        return 1;
    }
    expr_end--;  // Ajustement pour pointer sur la dernière parenthèse fermante

    // Copie l'expression mathématique dans une chaîne de caractères
    wchar_t expression[256];
    wcsncpy(expression, expr_start, expr_end - expr_start);
    expression[expr_end - expr_start] = '\0';

    // Extraire l'argument (après la fermeture de l'expression lambda)
    wchar_t *arg_start = expr_end + 1;
    while (iswspace(*arg_start)) arg_start++;  // Ignore les espaces

    wchar_t argument_value[100];
    Variable arg_var;
    int variable_defined = 0;

    // Vérifie si l'argument est un nombre ou une variable définie
    if (swscanf(arg_start, L"%lf", &arg_var.value.float_value) == 1) {
        // L'argument est un nombre, on le transforme en chaîne
        swprintf(argument_value, sizeof(argument_value) / sizeof(wchar_t), L"%.2f", arg_var.value.float_value);
        variable_defined = 1;  // Marque la variable comme définie
    } else if (get_variable(arg_start, &arg_var)) {
        // L'argument est une variable définie, on récupère sa valeur
        switch (arg_var.type) {
            case TYPE_INT:
                swprintf(argument_value, sizeof(argument_value) / sizeof(wchar_t), L"%d", arg_var.value.int_value);
                variable_defined = 1;
                break;
            case TYPE_FLOAT:
                swprintf(argument_value, sizeof(argument_value) / sizeof(wchar_t), L"%.2f", arg_var.value.float_value);
                variable_defined = 1;
                break;
            default:
                wprintf(L"Erreur : les chaînes de caractères ne sont pas autorisées comme argument de substitution.\n");
                return 1;
        }
    }

    // Affiche une erreur unique si la variable n'est pas définie, et quitte la fonction
    if (!variable_defined) {
        wprintf(L"Erreur : la variable %ls n'est pas définie\n", arg_start);
        return 1;  // Retour immédiat pour éviter tout traitement supplémentaire
    }

    // Remplacement de la variable dans l'expression par la valeur de l'argument
    wchar_t substituted_expression[256];
    substitute_variable(expression, variable, argument_value, substituted_expression);

    // Conversion de wchar_t* en char* pour la notation postfixée et l'évaluation
    char char_expression[256];
    char char_postfix[256];
    wchar_to_char(substituted_expression, char_expression, sizeof(char_expression));
    
    infix_to_postfix(char_expression, char_postfix);

    // Évaluation de l'expression postfixée et affichage du résultat
    double result = evaluate_postfix(char_postfix);
    wprintf(L"Résultat : %f\n", result);
    return 1;
}

// Fonction principale de l'interpréteur
int main() {
    wchar_t input[MAX_EXPR_LENGTH];
    init_interpreter();

    while (1) {
        wprintf(L"> ");
        fgetws(input, sizeof(input) / sizeof(input[0]), stdin);

        // Supprime le saut de ligne final
        input[wcscspn(input, L"\n")] = 0;

        // Commandes de sortie
        if (wcscasecmp(input, L"quit") == 0 || wcscasecmp(input, L"quitter") == 0) {
            wprintf(L"Arrêt du programme...\n");
            break;
        }

        // Gestion des expressions lambda
        if (handle_lambda_expression(input)) continue;

        // Affectation de variable
        wchar_t *equals_sign = wcschr(input, L'=');
        if (equals_sign != NULL) {
            *equals_sign = L'\0'; // Séparation nom et valeur
            wchar_t *name = input;
            wchar_t *value = equals_sign + 1;
            while (iswspace(*name)) name++;   // Ignore les espaces
            while (iswspace(*value)) value++;
            set_variable(name, value);        // Enregistre la variable
        } else {
            // Affichage de la valeur de la variable
            Variable var;
            if (get_variable(input, &var)) {
                wprintf(L"Valeur de %ls : ", input);
                print_variable(&var);
                wprintf(L"\n");
            } else {
                wprintf(L"Commande non reconnue ou variable non définie.\n");
            }
        }
        wprintf(L"\n");
    }
    return 0;
}
