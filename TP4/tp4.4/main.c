// main.c
#include <stdio.h>              // Inclusion pour les fonctions d'entrées/sorties standard (ex. printf, fgets)
#include <string.h>             // Inclusion pour les fonctions de manipulation de chaînes (ex. strchr, strcasecmp)
#include <ctype.h>              // Inclusion pour les fonctions de classification de caractères (ex. isdigit)
#include "postfixe.h"           // Inclusion pour les fonctions de conversion infix à postfix
#include "evaluation_postfixe.h" // Inclusion pour les fonctions d'évaluation d'expression postfixée

/**
 * Détecte si une chaîne de caractères est une expression arithmétique.
 * Une expression arithmétique doit contenir à la fois des chiffres et des opérateurs.
 * @param input La chaîne à analyser.
 * @return 1 si c'est une expression arithmétique, sinon 0.
 */
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

/**
 * Évalue une expression arithmétique en notation infixée en la convertissant d'abord en postfixée.
 * @param input La chaîne représentant l'expression en notation infixée.
 */
void evaluate_expression(const char *input) {
    char postfix[MAX_EXPR_LENGTH];
    infix_to_postfix(input, postfix); // Convertit l'infixe en postfixe
    printf("Expression en notation postfixée : %s\n", postfix);
    
    double result = evaluate_postfix(postfix); // Évalue l'expression postfixée
    printf("Résultat de l'évaluation : %f\n", result); // Affiche le résultat
}

/**
 * Programme principal qui lit des commandes de l'utilisateur en boucle.
 * Permet de saisir des expressions arithmétiques en notation infixée, qui sont évaluées
 * ou des commandes de sortie ("quit" ou "quitter") pour arrêter le programme.
 */
int main() {
    char input[MAX_EXPR_LENGTH];

    while (1) { // Boucle principale pour lire les commandes
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Supprime le caractère de fin de ligne pour traiter la commande
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
