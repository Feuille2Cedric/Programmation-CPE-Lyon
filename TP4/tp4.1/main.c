// main.c
#include <stdio.h>
#include "postfixe.h"
#include "evaluation_postfixe.h" // Inclut le fichier d'en-tête plutôt que le fichier source

int main() {
    char infix[MAX_EXPR_LENGTH];
    char postfix[MAX_EXPR_LENGTH];
    
    printf("Entrez une expression en notation infixée : ");
    fgets(infix, sizeof(infix), stdin);
    
    infix_to_postfix(infix, postfix);
    printf("Expression en notation postfixée : %s\n", postfix);
    
    double result = evaluate_postfix(postfix);
    printf("Résultat de l'évaluation : %f\n", result);
    
    return 0;
}

