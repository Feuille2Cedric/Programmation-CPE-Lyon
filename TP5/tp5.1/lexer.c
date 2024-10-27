// lexer.c
#include "lexer.h"    // Inclusion du fichier d'en-tête pour les définitions de types et fonctions du lexer
#include <ctype.h>    // Inclusion pour utiliser les fonctions de manipulation de caractères (ex. isspace, isdigit)
#include <stdlib.h>   // Inclusion pour utiliser strtod, qui convertit une chaîne en double
#include <stdio.h>    // Inclusion pour la gestion des entrées/sorties (ici, potentiellement pour le débogage)

static const char *input; // Pointeur vers l'expression à analyser lexicalement
static int position = 0;  // Position actuelle dans l'expression pour suivre l'analyse

/**
 * Initialise le lexer avec une chaîne d'entrée.
 * @param str La chaîne de caractères représentant l'expression à analyser.
 */
void init_lexer(const char *str) {
    input = str;   // Définition de l'expression à analyser
    position = 0;  // Réinitialisation de la position de début
}

Token get_next_token() {
    Token token;
    while (input[position] != '\0') {
        // Ignorer les espaces et passer au prochain caractère significatif
        if (isspace(input[position])) {
            position++;
            continue;
        }

        // Détection d'un nombre (inclut les chiffres et le point décimal)
        if (isdigit(input[position]) || input[position] == '.') {
            token.type = TOKEN_NUMBER;
            char *end;
            token.value = strtod(&input[position], &end); // Conversion de la sous-chaîne en double
            position = end - input;  // Mise à jour de la position après le nombre
            return token;
        }

        // Détection de l'opérateur '+'
        if (input[position] == '+') {
            token.type = TOKEN_PLUS;
            position++;
            return token;
        }

        // Détection de l'opérateur '-'
        if (input[position] == '-') {
            token.type = TOKEN_MINUS;
            position++;
            return token;
        }

        // Détection de l'opérateur '*'
        if (input[position] == '*') {
            token.type = TOKEN_MULTIPLY;
            position++;
            return token;
        }

        // Détection de l'opérateur '/'
        if (input[position] == '/') {
            token.type = TOKEN_DIVIDE;
            position++;
            return token;
        }

        // Caractère non reconnu, retourne un token d'erreur
        token.type = TOKEN_ERROR;
        return token;
    }
    
    // Retour d'un token de fin lorsque tous les caractères ont été analysés
    token.type = TOKEN_END;
    return token;
}
