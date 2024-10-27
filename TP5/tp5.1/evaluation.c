// evaluation.c
#include "evaluation.h"  // Inclusion des définitions liées à l'évaluation d'expressions
#include <stdio.h>       // Inclusion pour utiliser la fonction printf pour les erreurs

double evaluate_expression(const Expression *expression, int *error) {
    *error = 0;  // Initialisation de l'indicateur d'erreur à 0 (aucune erreur par défaut)

    // Choix de l'opération selon le champ `operation` de la structure `Expression`
    switch (expression->operation) {
        case TOKEN_PLUS:
            return expression->operande1 + expression->operande2;  // Addition

        case TOKEN_MINUS:
            return expression->operande1 - expression->operande2;  // Soustraction

        case TOKEN_MULTIPLY:
            return expression->operande1 * expression->operande2;  // Multiplication

        case TOKEN_DIVIDE:
            // Vérification pour éviter une division par zéro
            if (expression->operande2 == 0) {
                printf("Erreur : division par zéro.\n");  // Message d'erreur
                *error = 1;  // Marque l'erreur
                return 0;  // Retourne 0 en cas de division par zéro
            }
            return expression->operande1 / expression->operande2;  // Division si valide

        default:
            printf("Erreur : opérateur non supporté.\n");  // Message d'erreur pour opérateur inconnu
            *error = 1;  // Marque l'erreur
            return 0;  // Retourne 0 en cas d'opération non supportée
    }
}
