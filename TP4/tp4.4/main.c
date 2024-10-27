// main.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "postfixe.h"
#include "evaluation_postfixe.h"

// Fonction pour détecter si une chaîne de caractères est une expression arithmétique
// Retourne 1 si c'est une expression arithmétique, sinon 0
int is_arithmetic_expression(const char *input) {
    int contains_operator = 0;
    int contains_digit = 0;

    // Parcourt chaque caractère de l'entrée
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            contains_digit = 1; // Marque la présence d'un chiffre
        } else if (strchr("+-*/()", input[i])) {
            contains_operator = 1; // Marque la présence d'un opérateur
        }
    }
    // Une expression arithmétique doit contenir des chiffres et des opérateurs
    return contains_digit && contains_operator;
}

// Fonction pour évaluer une expression arithmétique en notation infixée
void evaluate_expression(const char *input) {
    char postfix[MAX_EXPR_LENGTH];
    infix_to_postfix(input, postfix); // Convertit l'infixe en postfixe
    printf("Expression en notation postfixée : %s\n", postfix);
    
    double result = evaluate_postfix(postfix); // Évalue l'expression postfixée
    printf("Résultat de l'évaluation : %f\n", result); // Affiche le résultat
}

int main() {
    char input[MAX_EXPR_LENGTH];

    while (1) { // Boucle principale pour lire les commandes
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Supprime le caractère de fin de ligne
        input[strcspn(input, "\n")] = 0;

        // Vérifie si la commande est pour quitter le programme
        if (strcasecmp(input, "quit") == 0 || strcasecmp(input, "quitter") == 0) {
            printf("Arrêt du programme...\n");
            break;
        } 
        // Si c'est une expression arithmétique, on l'évalue
        else if (is_arithmetic_expression(input)) {
            evaluate_expression(input);
        } 
        // Message si la commande n'est ni une expression, ni "quit"
        else {
            printf("Commande non reconnue ou sans expression arithmétique.\n");
        }

        printf("\n");
    }

    return 0;
}
