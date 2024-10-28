// main.c
#include <stdio.h>                // Inclusion pour les fonctions d'entrées/sorties (ex. printf, fgets)
#include "postfixe.h"             // Inclusion pour la conversion de l'expression de notation infixée à postfixée
#include "evaluation_postfixe.h"  // Inclusion pour l'évaluation d'une expression en notation postfixée

int main() {
    char infix[MAX_EXPR_LENGTH];   // Buffer pour stocker l'expression infixée entrée par l'utilisateur
    char postfix[MAX_EXPR_LENGTH]; // Buffer pour stocker l'expression convertie en notation postfixée
    
    // Demande à l'utilisateur de saisir une expression en notation infixée
    printf("Entrez une expression en notation infixée : ");
    fgets(infix, sizeof(infix), stdin);  // Lecture de l'expression de l'utilisateur
    
    // Conversion de l'expression de notation infixée à notation postfixée
    infix_to_postfix(infix, postfix);
    printf("Expression en notation postfixée : %s\n", postfix);
    
    // Évaluation de l'expression en notation postfixée et affichage du résultat
    double result = evaluate_postfix(postfix);
    printf("Résultat de l'évaluation : %f\n", result);
    
    return 0;
}
