// evaluation_postfixe.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "evaluation_postfixe.h"

// Initialisation de la pile pour les doubles
void init_double_stack(DoubleStack *stack) {
    stack->top = -1;
}

// Vérifie si la pile est vide
int double_stack_is_empty(DoubleStack *stack) {
    return stack->top == -1;
}

// Empile un double sur la pile
void push_double(DoubleStack *stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->items[++stack->top] = value;
    }
}

// Dépile un double de la pile
double pop_double(DoubleStack *stack) {
    return stack->top != -1 ? stack->items[stack->top--] : 0;
}

// Fonction d'évaluation d'une expression en notation postfixée
double evaluate_postfix(const char *postfix) {
    DoubleStack stack;
    init_double_stack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        // Ignorer les espaces
        if (isspace(postfix[i])) continue;

        // Si l'on rencontre un nombre, le lire et l'empiler
        if (isdigit(postfix[i]) || postfix[i] == '.') {
            char number[STACK_SIZE];
            int j = 0;

            // Extraire le nombre
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                number[j++] = postfix[i++];
            }
            number[j] = '\0';
            push_double(&stack, atof(number));
            i--; // Revenir d'un caractère pour l'analyse continue
        }
        // Si un opérateur est rencontré
        else {
            double operand2 = pop_double(&stack);
            double operand1 = pop_double(&stack);

            switch (postfix[i]) {
                case '+': push_double(&stack, operand1 + operand2); break;
                case '-': push_double(&stack, operand1 - operand2); break;
                case '*': push_double(&stack, operand1 * operand2); break;
                case '/':
                    if (operand2 == 0) {
                        printf("Erreur : division par zéro\n");
                        return 0;
                    }
                    push_double(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Erreur : opérateur non valide '%c'\n", postfix[i]);
                    return 0;
            }
        }
    }

    // Le résultat final est le seul élément restant sur la pile
    return pop_double(&stack);
}
