// main.c
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include "postfixe.h"
#include "evaluation_postfixe.h"
#include "variables.h"

// Initialisation de l'interpréteur : configuration de la localisation pour la gestion UTF-8
void init_interpreter() {
    setlocale(LC_ALL, "");
    init_variables(); // Initialise la table de symboles (variables)
}

int main() {
    wchar_t input[MAX_EXPR_LENGTH];
    init_interpreter(); // Configure l'interpréteur

    while (1) { // Boucle principale pour les commandes utilisateur
        wprintf(L"> "); // Affiche l'invite de commande
        fgetws(input, sizeof(input) / sizeof(input[0]), stdin); // Lit l'entrée utilisateur

        // Supprime le caractère de fin de ligne de l'entrée
        input[wcscspn(input, L"\n")] = 0;

        // Vérifie si la commande est "quit" ou "quitter" pour arrêter l'interpréteur
        if (wcscasecmp(input, L"quit") == 0 || wcscasecmp(input, L"quitter") == 0) {
            wprintf(L"Arrêt du programme...\n");
            break;
        }

        // Détection d'une affectation de variable (présence de "=")
        wchar_t *equals_sign = wcschr(input, L'=');
        if (equals_sign != NULL) {
            // Sépare la variable et sa valeur
            *equals_sign = L'\0';
            wchar_t *name = input;
            wchar_t *value = equals_sign + 1;

            // Supprime les espaces autour du nom et de la valeur
            while (iswspace(*name)) name++;
            while (iswspace(*value)) value++;

            set_variable(name, value); // Affecte la valeur à la variable
        } 
        // Vérifie si l'entrée est uniquement un nom de variable pour afficher sa valeur
        else {
            Variable var;
            if (get_variable(input, &var)) { // Vérifie si la variable existe
                wprintf(L"Valeur de %ls : ", input);
                print_variable(&var); // Affiche la valeur de la variable
                wprintf(L"\n");
            } else {
                wprintf(L"Commande non reconnue ou variable non définie.\n"); // Message d'erreur
            }
        }

        wprintf(L"\n"); // Saut de ligne pour la lisibilité
    }

    return 0;
}
