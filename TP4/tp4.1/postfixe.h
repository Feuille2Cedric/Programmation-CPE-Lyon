// postfixe.h
#ifndef POSTFIXE_H
#define POSTFIXE_H

#include <stddef.h> // Ajouté pour size_t

#define MAX_EXPR_LENGTH 256
#define STACK_SIZE 100 // Déplacement ici pour accès global

// Fonction pour vérifier la priorité d'un opérateur
int precedence(char op);

// Fonction pour convertir une expression infixée en postfixée
void infix_to_postfix(const char *infix, char *postfix);

#endif // POSTFIXE_H
