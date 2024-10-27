// evaluation.c
#include "evaluation.h"
#include <stdio.h>

double evaluate_expression(const Expression *expression, int *error) {
    *error = 0;

    switch (expression->operation) {
        case TOKEN_PLUS:
            return expression->operande1 + expression->operande2;
        case TOKEN_MINUS:
            return expression->operande1 - expression->operande2;
        case TOKEN_MULTIPLY:
            return expression->operande1 * expression->operande2;
        case TOKEN_DIVIDE:
            if (expression->operande2 == 0) {
                printf("Erreur : division par zéro.\n");
                *error = 1;
                return 0;
            }
            return expression->operande1 / expression->operande2;
        default:
            printf("Erreur : opérateur non supporté.\n");
            *error = 1;
            return 0;
    }
}
