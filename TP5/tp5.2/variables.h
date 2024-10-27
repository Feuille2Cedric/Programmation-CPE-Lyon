// variables.h
#ifndef VARIABLES_H
#define VARIABLES_H

#include <wchar.h>

// Enumération pour les types de variables
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} VariableType;

// Structure pour représenter une variable
typedef struct {
    wchar_t *name;       // Nom de la variable (en UTF-8)
    VariableType type;   // Type de la variable
    union {              // Valeur de la variable, dépendant du type
        int int_value;
        double float_value;
        wchar_t *string_value;
    } value;
} Variable;

#define MAX_VARIABLES 100 // Limite de variables

// Prototypes des fonctions pour gérer les variables
void init_variables();
int set_variable(const wchar_t *name, const wchar_t *value);
int get_variable(const wchar_t *name, Variable *result);
void print_variable(const Variable *var);

#endif // VARIABLES_H
