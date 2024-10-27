// postfixe.c
#include "postfixe.h"    // Inclusion pour les définitions de fonctions et structures pour la conversion postfixe
#include <string.h>      // Inclusion pour les manipulations de chaînes de caractères
#include <ctype.h>       // Inclusion pour les fonctions de classification de caractères (ex. isdigit)
#include <stdlib.h>      // Inclusion pour la gestion des conversions numériques (ex. atoi)
#include <stdio.h>       // Inclusion pour la gestion des sorties (ex. printf)

#define STACK_SIZE 100   // Définition de la taille maximale de la pile pour stocker les opérateurs

// Structure pour une pile simple de caractères pour gérer les opérateurs
typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

// Initialise la pile en fixant son sommet à -1
void init_stack(Stack *stack) {
    stack->top = -1;
}

// Vérifie si la pile est vide
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Vérifie si la pile est pleine
int is_full(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

// Empile un élément dans la pile
void push(Stack *stack, char value) {
    if (!is_full(stack)) {
        stack->items[++stack->top] = value;
    }
}

// Dépile un élément de la pile et le retourne
char pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0'; // Retourne '\0' si la pile est vide
}

// Renvoie l'élément au sommet de la pile sans le dépiler
char peek(Stack *stack) {
    return is_empty(stack) ? '\0' : stack->items[stack->top];
}

// Détermine la priorité d'un opérateur pour l'organisation en notation postfixée
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(const char *infix, char *postfix) {
    Stack operators;
    init_stack(&operators);  // Initialise la pile pour les opérateurs
    int k = 0;               // Index pour construire la chaîne de sortie postfixée

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isspace(infix[i])) continue; // Ignore les espaces

        // Ajoute directement un opérande (nombre) à la sortie
        if (isdigit(infix[i]) || infix[i] == '.') {
            postfix[k++] = infix[i];
            // Ajoute un espace après le nombre pour bien séparer dans la notation postfixée
            if (!isdigit(infix[i + 1]) && infix[i + 1] != '.') {
                postfix[k++] = ' ';
            }
        }
        // Empile les parenthèses ouvrantes
        else if (infix[i] == '(') {
            push(&operators, infix[i]);
        }
        // Pour une parenthèse fermante, dépile jusqu'à la parenthèse ouvrante
        else if (infix[i] == ')') {
            while (!is_empty(&operators) && peek(&operators) != '(') {
                postfix[k++] = pop(&operators);
                postfix[k++] = ' ';
            }
            if (!is_empty(&operators) && peek(&operators) == '(') {
                pop(&operators); // Supprime la parenthèse ouvrante
            }
        }
        // Si un opérateur est rencontré, traite la pile selon la priorité
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!is_empty(&operators) && precedence(peek(&operators)) >= precedence(infix[i])) {
                postfix[k++] = pop(&operators);
                postfix[k++] = ' ';
            }
            push(&operators, infix[i]);
        }
    }

    // Vide la pile des opérateurs restants pour les ajouter à la sortie
    while (!is_empty(&operators)) {
        postfix[k++] = pop(&operators);
        postfix[k++] = ' ';
    }
    postfix[k - 1] = '\0'; // Remplace le dernier espace par le caractère de fin de chaîne
}
