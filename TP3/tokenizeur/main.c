// main.c
#include <stdio.h>
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"

int main() {
    char input[256];
    printf("Entrez une expression (ex. 3 + 4) : ");
    fgets(input, sizeof(input), stdin);

    Expression expr;
    if (!parse_expression(input, &expr)) {
        printf("Erreur de syntaxe dans l'expression.\n");
        return 1;
    }

    int error;
    double result = evaluate_expression(&expr, &error);
    if (!error) {
        printf("Résultat : %f\n", result);
    }

    return 0;
}
