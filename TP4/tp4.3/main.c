// main.c
#include <stdio.h>                // Inclusion pour les fonctions d'entrées/sorties standard (ex. printf, fgets)
#include "postfixe.h"             // Inclusion pour les fonctions de conversion d'une expression infixée en postfixée
#include "evaluation_postfixe.h"   // Inclusion pour les fonctions d'évaluation d'une expression postfixée

int main() {
    char infix[MAX_EXPR_LENGTH];   // Buffer pour stocker l'expression en notation infixée entrée par l'utilisateur
    char postfix[MAX_EXPR_LENGTH]; // Buffer pour stocker l'expression convertie en notation postfixée
    
    // Demande à l'utilisateur de saisir une expression en notation infixée
    printf("Entrez une expression en notation infixée : ");
    fgets(infix, sizeof(infix), stdin);  // Lecture de l'expression saisie par l'utilisateur
    
    // Conversion de l'expression de notation infixée à notation postfixée
    infix_to_postfix(infix, postfix);
    printf("Expression en notation postfixée : %s\n", postfix);
    
    // Évaluation de l'expression en notation postfixée et affichage du résultat
    double result = evaluate_postfix(postfix);
    printf("Résultat de l'évaluation : %f\n", result);
    
    return 0;  // Indique que le programme s'est terminé avec succès
}
