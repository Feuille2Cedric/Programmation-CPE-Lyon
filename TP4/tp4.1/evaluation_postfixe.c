// evaluation_postfixe.c
#include <stdio.h>              // Inclusion pour les entrées/sorties standard (ex. printf)
#include <stdlib.h>             // Inclusion pour les conversions numériques (ex. atof)
#include <ctype.h>              // Inclusion pour les fonctions de manipulation de caractères (ex. isdigit)
#include "evaluation_postfixe.h" // Inclusion pour les définitions des structures et fonctions d'évaluation postfixe

/**
 * Initialise une pile de type `DoubleStack`.
 * @param stack Pointeur vers la pile à initialiser.
 */
void init_double_stack(DoubleStack *stack) {
    stack->top = -1;
}

/**
 * Vérifie si la pile est vide.
 * @param stack Pile à vérifier.
 * @return 1 si la pile est vide, 0 sinon.
 */
int double_stack_is_empty(DoubleStack *stack) {
    return stack->top == -1;
}

/**
 * Empile une valeur de type double dans la pile.
 * @param stack Pile dans laquelle empiler la valeur.
 * @param value La valeur à empiler.
 */
void push_double(DoubleStack *stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->items[++stack->top] = value;
    }
}

/**
 * Dépile et retourne une valeur de type double depuis la pile.
 * @param stack Pile depuis laquelle dépiler.
 * @return La valeur dépilée, ou 0 si la pile est vide.
 */
double pop_double(DoubleStack *stack) {
    return stack->top != -1 ? stack->items[stack->top--] : 0;
}

/**
 * Évalue une expression en notation postfixée (suffixée).
 * @param postfix Chaîne représentant l'expression en notation postfixée.
 * @return Le résultat de l'évaluation de l'expression.
 */
double evaluate_postfix(const char *postfix) {
    DoubleStack stack;
    init_double_stack(&stack);  // Initialise la pile pour les calculs

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isspace(postfix[i])) continue;  // Ignore les espaces

        // Si le caractère est un chiffre ou un point, l'interprète comme un nombre
        if (isdigit(postfix[i]) || postfix[i] == '.') {
            char number[STACK_SIZE];
            int j = 0;
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                number[j++] = postfix[i++];  // Stocke chaque caractère numérique
            }
            number[j] = '\0';  // Termine la chaîne pour conversion
            push_double(&stack, atof(number));  // Convertit et empile le nombre
            i--;  // Réajuste l'index pour le prochain caractère
        }
        else {  // Traitement des opérateurs
            double operand2 = pop_double(&stack);  // Deuxième opérande
            double operand1 = pop_double(&stack);  // Premier opérande
            switch (postfix[i]) {
                case '+': push_double(&stack, operand1 + operand2); break;
                case '-': push_double(&stack, operand1 - operand2); break;
                case '*': push_double(&stack, operand1 * operand2); break;
                case '/':  // Vérifie la division par zéro
                    if (operand2 == 0) {
                        printf("Erreur : division par zéro\n");
                        return 0;
                    }
                    push_double(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop_double(&stack);  // Retourne le résultat final de l'expression
}
