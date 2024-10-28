// lexer.c
#include "lexer.h"    // Inclusion pour les définitions de types et fonctions du lexer
#include <ctype.h>    // Inclusion pour les fonctions de manipulation de caractères (ex. isspace, isdigit)
#include <stdlib.h>   // Inclusion pour utiliser strtod (conversion de chaîne en double)
#include <stdio.h>    // Inclusion pour les fonctions d'entrées/sorties (ex. printf)

static const char *input; // Pointeur vers la chaîne de caractères représentant l'expression à analyser
static int position = 0;  // Position actuelle dans la chaîne, utilisée pour suivre la progression de l'analyse

/**
 * Initialise le lexer avec la chaîne d'entrée.
 * @param str La chaîne représentant l'expression à analyser.
 */
void init_lexer(const char *str) {
    input = str;   // Définit l'expression à analyser
    position = 0;  // Réinitialise la position de départ pour l'analyse
}

/**
 * Analyse et retourne le prochain token dans l'expression.
 * La fonction identifie les nombres, les opérateurs (+, -, *, /), ou signale une erreur
 * pour les caractères non reconnus.
 * @return Le prochain token détecté ou un token d'erreur si le caractère est invalide.
 */
Token get_next_token() {
    Token token;
    while (input[position] != '\0') {
        // Ignore les espaces et avance la position
        if (isspace(input[position])) {
            position++;
            continue;
        }

        // Vérifie si le caractère est un nombre (chiffre ou point) et le convertit
        if (isdigit(input[position]) || input[position] == '.') {
            token.type = TOKEN_NUMBER;
            char *end;
            token.value = strtod(&input[position], &end); // Convertit la sous-chaîne en double
            position = end - input;  // Met à jour la position après le nombre
            return token;
        }

        // Vérifie et retourne les différents opérateurs
        if (input[position] == '+') {
            token.type = TOKEN_PLUS;
            position++;
            return token;
        }

        if (input[position] == '-') {
            token.type = TOKEN_MINUS;
            position++;
            return token;
        }

        if (input[position] == '*') {
            token.type = TOKEN_MULTIPLY;
            position++;
            return token;
        }

        if (input[position] == '/') {
            token.type = TOKEN_DIVIDE;
            position++;
            return token;
        }

        // Retourne un token d'erreur si le caractère n'est pas reconnu
        token.type = TOKEN_ERROR;
        return token;
    }
    
    // Si la fin de l'expression est atteinte, retourne un token de fin
    token.type = TOKEN_END;
    return token;
}
