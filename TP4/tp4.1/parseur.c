// parseur.c
#include "parseur.h"   // Inclusion pour accéder aux définitions des structures et fonctions de parsing
#include <stdio.h>      // Inclusion pour utiliser printf pour les messages d'erreur

int parse_expression(const char *input, Expression *expression) {
    init_lexer(input);  // Initialise le lexer avec l'expression en entrée
    Token token = get_next_token();

    // Vérifie que le premier token est un nombre (premier opérande)
    if (token.type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe : nombre attendu au début de l'expression.\n");
        return 0;  // Retourne 0 si la syntaxe est incorrecte
    }
    expression->operande1 = token.value;  // Stocke le premier opérande dans `expression`

    // Obtient le prochain token et vérifie qu'il s'agit d'un opérateur valide
    token = get_next_token();
    if (token.type != TOKEN_PLUS && token.type != TOKEN_MINUS &&
        token.type != TOKEN_MULTIPLY && token.type != TOKEN_DIVIDE) {
        printf("Erreur de syntaxe : opérateur attendu.\n");
        return 0;  // Retourne 0 si la syntaxe est incorrecte
    }
    expression->operation = token.type;  // Stocke l'opérateur dans `expression`

    // Obtient le prochain token et vérifie qu'il s'agit d'un deuxième nombre (second opérande)
    token = get_next_token();
    if (token.type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe : nombre attendu après l'opérateur.\n");
        return 0;  // Retourne 0 si la syntaxe est incorrecte
    }
    expression->operande2 = token.value;  // Stocke le deuxième opérande dans `expression`

    return 1;  // Retourne 1 si l'expression est correctement analysée
}
