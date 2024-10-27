// evaluation.c
#include "evaluation.h"  // Inclusion pour les définitions de structures et constantes de l'évaluation
#include <stdio.h>       // Inclusion pour utiliser printf pour les messages d'erreur

double evaluate_expression(const Expression *expression, int *error) {
    *error = 0;  // Initialisation de l'erreur à 0 (pas d'erreur)

    // Effectue l'opération en fonction du type spécifié dans `expression->operation`
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
                *error = 1;  // Signale l'erreur
                return 0;    // Retourne 0 si la division est invalide
            }
            return expression->operande1 / expression->operande2;  // Division
        default:
            // Gestion d'un opérateur non reconnu
            printf("Erreur : opérateur non supporté.\n");
            *error = 1;  // Signale l'erreur
            return 0;    // Retourne 0 en cas d'opération non supportée
    }
}
