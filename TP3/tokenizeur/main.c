// main.c
#include <stdio.h>         // Inclusion pour les entrées/sorties standard (ex. printf, fgets)
#include "lexer.h"         // Inclusion pour les fonctions du lexer
#include "parseur.h"       // Inclusion pour les fonctions du parseur
#include "evaluation.h"    // Inclusion pour les fonctions d'évaluation

int main() {
    char input[256];  // Buffer pour stocker l'expression entrée par l'utilisateur
    printf("Entrez une expression (ex. 3 + 4) : ");
    fgets(input, sizeof(input), stdin);  // Lecture de l'entrée utilisateur

    Expression expr;  // Structure pour stocker l'expression analysée
    if (!parse_expression(input, &expr)) {
        printf("Erreur de syntaxe dans l'expression.\n");
        return 1;  // Retourne 1 en cas d'erreur de syntaxe
    }

    int error;  // Indicateur d'erreur pour l'évaluation
    double result = evaluate_expression(&expr, &error);  // Évalue l'expression
    if (!error) {
        printf("Résultat : %f\n", result);  // Affiche le résultat si aucune erreur
    }

    return 0;
}
