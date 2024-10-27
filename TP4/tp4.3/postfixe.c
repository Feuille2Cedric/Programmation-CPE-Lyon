// postfixe.c
#include "postfixe.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (!is_full(stack)) {
        stack->items[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0'; // Valeur par défaut si la pile est vide
}

char peek(Stack *stack) {
    return is_empty(stack) ? '\0' : stack->items[stack->top];
}

// Fonction pour déterminer la priorité d'un opérateur
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Fonction de conversion d'infixe à postfixe, avec support des parenthèses
void infix_to_postfix(const char *infix, char *postfix) {
    Stack operators;
    init_stack(&operators);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isspace(infix[i])) continue;

        // Si l'on rencontre un opérande (nombre), on l'ajoute directement à la sortie
        if (isdigit(infix[i]) || infix[i] == '.') {
            postfix[k++] = infix[i];
            // Ajoute un espace après le nombre pour le séparer dans la sortie postfixée
            if (!isdigit(infix[i+1]) && infix[i+1] != '.') {
                postfix[k++] = ' ';
            }
        }
        // Si une parenthèse ouvrante est rencontrée, la pousser sur la pile
        else if (infix[i] == '(') {
            push(&operators, infix[i]);
        }
        // Si une parenthèse fermante est rencontrée, dépiler jusqu'à '('
        else if (infix[i] == ')') {
            while (!is_empty(&operators) && peek(&operators) != '(') {
                postfix[k++] = pop(&operators);
                postfix[k++] = ' ';
            }
            if (!is_empty(&operators) && peek(&operators) == '(') {
                pop(&operators); // Supprimer la parenthèse ouvrante de la pile
            }
        }
        // Si un opérateur est rencontré
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!is_empty(&operators) && precedence(peek(&operators)) >= precedence(infix[i])) {
                postfix[k++] = pop(&operators);
                postfix[k++] = ' ';
            }
            push(&operators, infix[i]);
        }
    }

    // Dépiler les opérateurs restants dans la pile
    while (!is_empty(&operators)) {
        postfix[k++] = pop(&operators);
        postfix[k++] = ' ';
    }
    postfix[k - 1] = '\0'; // Remplace le dernier espace par un terminateur
}
