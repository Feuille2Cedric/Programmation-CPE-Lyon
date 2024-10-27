// lexer.c
#include "lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

static const char *input; // Expression à analyser
static int position = 0;  // Position actuelle dans l'expression

void init_lexer(const char *str) {
    input = str;
    position = 0;
}

Token get_next_token() {
    Token token;
    while (input[position] != '\0') {
        if (isspace(input[position])) {
            position++;
            continue;
        }

        if (isdigit(input[position]) || input[position] == '.') {
            token.type = TOKEN_NUMBER;
            char *end;
            token.value = strtod(&input[position], &end);
            position = end - input;
            return token;
        }

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

        // Si aucun des cas ci-dessus n'est rencontré, c'est une erreur
        token.type = TOKEN_ERROR;
        return token;
    }
    
    token.type = TOKEN_END;
    return token;
}
