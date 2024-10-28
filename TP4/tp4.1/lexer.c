// lexer.c
#include "lexer.h"    // Inclusion pour les définitions de types et fonctions du lexer
#include <ctype.h>    // Inclusion pour les fonctions de manipulation de caractères (isspace, isdigit)
#include <stdlib.h>   // Inclusion pour utiliser strtod (conversion de chaîne en double)
#include <stdio.h>    // Inclusion pour la gestion des sorties d'erreur (ex. printf)

static const char *input; // Pointeur vers la chaîne d'expression à analyser
static int position = 0;  // Position actuelle dans la chaîne pour suivre l'analyse

/**
 * Initialise le lexer avec la chaîne d'entrée.
 * @param str La chaîne représentant l'expression à analyser.
 */
void init_lexer(const char *str) {
    input = str;   // Définit l'expression à analyser
    position = 0;  // Réinitialise la position de départ pour l'analyse
}

Token get_next_token() {
    Token token;
    while (input[position] != '\0') {
        // Ignore les espaces et passe au caractère suivant
        if (isspace(input[position])) {
            position++;
            continue;
        }

        // Si un nombre est trouvé (chiffre ou point), le convertir et avancer la position
        if (isdigit(input[position]) || input[position] == '.') {
            token.type = TOKEN_NUMBER;
            char *end;
            token.value = strtod(&input[position], &end); // Convertit la chaîne en double
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

        // Retourne un token d'erreur si le caractère est non reconnu
        token.type = TOKEN_ERROR;
        return token;
    }
    
    // Si l'expression est terminée, retourne un token de fin
    token.type = TOKEN_END;
    return token;
}
