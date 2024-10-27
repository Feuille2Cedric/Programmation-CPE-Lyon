// lexer.h
#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,   // Pour les nombres entiers ou réels
    TOKEN_PLUS,     // Pour l'opérateur +
    TOKEN_MINUS,    // Pour l'opérateur -
    TOKEN_MULTIPLY, // Pour l'opérateur *
    TOKEN_DIVIDE,   // Pour l'opérateur /
    TOKEN_END,      // Pour indiquer la fin de l'expression
    TOKEN_ERROR     // Pour les erreurs de syntaxe
} TokenType;

typedef struct {
    TokenType type;
    double value;   // Pour stocker les valeurs numériques
} Token;

// Fonction pour initialiser le tokenizer
void init_lexer(const char *input);

// Fonction pour obtenir le token suivant
Token get_next_token();

#endif // LEXER_H
