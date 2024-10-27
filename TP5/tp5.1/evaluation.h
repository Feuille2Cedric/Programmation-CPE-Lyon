// evaluation.h
#ifndef EVALUATION_H
#define EVALUATION_H

#include "parseur.h"  // Inclusion de parseur.h pour accéder à la structure Expression

// Déclaration de la fonction d'évaluation de l'expression arithmétique.
// Cette fonction prend en paramètre un pointeur vers une structure Expression
// et un pointeur vers un entier pour signaler les erreurs éventuelles.
// Elle retourne un résultat de type double.
double evaluate_expression(const Expression *expression, int *error);

#endif // EVALUATION_H
