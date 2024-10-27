// parseur.h
#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"

typedef struct {
    TokenType operation;
    double operande1;
    double operande2;
} Expression;

// Fonction pour initialiser le parseur avec une expression mathématique
int parse_expression(const char *input, Expression *expression);

#endif // PARSEUR_H
