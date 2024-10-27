// evaluation_postfixe.h
#ifndef EVALUATION_POSTFIXE_H
#define EVALUATION_POSTFIXE_H

#include "postfixe.h"

// Structure pour la pile de doubles
typedef struct {
    double items[STACK_SIZE];
    int top;
} DoubleStack;

// Initialisation de la pile pour les doubles
void init_double_stack(DoubleStack *stack);

// Vérifie si la pile est vide
int double_stack_is_empty(DoubleStack *stack);

// Empile un double sur la pile
void push_double(DoubleStack *stack, double value);

// Dépile un double de la pile
double pop_double(DoubleStack *stack);

// Évalue une expression en notation postfixée
double evaluate_postfix(const char *postfix);

#endif // EVALUATION_POSTFIXE_H

