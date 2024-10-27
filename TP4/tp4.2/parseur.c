// parseur.c
#include "parseur.h"
#include <stdio.h>

int parse_expression(const char *input, Expression *expression) {
    init_lexer(input);
    Token token = get_next_token();
    
    if (token.type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe : nombre attendu au début de l'expression.\n");
        return 0;
    }
    expression->operande1 = token.value;

    token = get_next_token();
    if (token.type != TOKEN_PLUS && token.type != TOKEN_MINUS &&
        token.type != TOKEN_MULTIPLY && token.type != TOKEN_DIVIDE) {
        printf("Erreur de syntaxe : opérateur attendu.\n");
        return 0;
    }
    expression->operation = token.type;

    token = get_next_token();
    if (token.type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe : nombre attendu après l'opérateur.\n");
        return 0;
    }
    expression->operande2 = token.value;

    return 1;
}
