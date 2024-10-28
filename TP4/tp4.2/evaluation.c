// evaluation.c
#include "evaluation.h"  // Inclusion pour les définitions de la structure Expression et des constantes d'opérations
#include <stdio.h>       // Inclusion pour utiliser printf pour les messages d'erreur

double evaluate_expression(const Expression *expression, int *error) {
    *error = 0;  // Initialisation de l'erreur à 0 (pas d'erreur)

    // Sélection de l'opération en fonction du type spécifié dans `expression->operation`
    switch (expression->operation) {
        case TOKEN_PLUS:
            return expression->operande1 + expression->operande2;  // Addition
        case TOKEN_MINUS:
            return expression->operande1 - expression->operande2;  // Soustraction
        case TOKEN_MULTIPLY:
            return expression->operande1 * expression->operande2;  // Multiplication
        case TOKEN_DIVIDE:
            // Gestion de la division par zéro
            if (expression->operande2 == 0) {
                printf("Erreur : division par zéro.\n");
                *error = 1;  // Indique l'erreur
                return 0;    // Retourne 0 en cas de division par zéro
            }
            return expression->operande1 / expression->operande2;  // Division
        default:
            // Gestion d'un opérateur non supporté
            printf("Erreur : opérateur non supporté.\n");
            *error = 1;  // Indique l'erreur
            return 0;    // Retourne 0 en cas d'opération non valide
    }
}
