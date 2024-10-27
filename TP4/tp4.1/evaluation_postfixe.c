// evaluation_postfixe.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "evaluation_postfixe.h"

void init_double_stack(DoubleStack *stack) {
    stack->top = -1;
}

int double_stack_is_empty(DoubleStack *stack) {
    return stack->top == -1;
}

void push_double(DoubleStack *stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->items[++stack->top] = value;
    }
}

double pop_double(DoubleStack *stack) {
    return stack->top != -1 ? stack->items[stack->top--] : 0;
}

double evaluate_postfix(const char *postfix) {
    DoubleStack stack;
    init_double_stack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isspace(postfix[i])) continue;

        if (isdigit(postfix[i]) || postfix[i] == '.') {
            char number[STACK_SIZE];
            int j = 0;
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                number[j++] = postfix[i++];
            }
            number[j] = '\0';
            push_double(&stack, atof(number));
            i--;
        }
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
            }
        }
    }
    return pop_double(&stack);
}
