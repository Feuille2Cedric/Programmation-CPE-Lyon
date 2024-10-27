// variables.c
#include "variables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>

static Variable variables[MAX_VARIABLES]; // Tableau de variables
static int variable_count = 0; // Compteur de variables

// Initialisation de la table des variables
void init_variables() {
    variable_count = 0;
}

// Remplace les virgules par des points dans une chaîne pour normaliser les décimales
void normalize_decimal_separator(wchar_t *value) {
    for (int i = 0; value[i] != L'\0'; i++) {
        if (value[i] == L',') {
            value[i] = L'.';
        }
    }
}

// Recherche d'une variable par son nom, retourne l'index ou -1 si non trouvé
static int find_variable(const wchar_t *name) {
    for (int i = 0; i < variable_count; i++) {
        if (wcscmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Ajoute ou met à jour une variable dans la table de symboles
int set_variable(const wchar_t *name, const wchar_t *value) {
    int index = find_variable(name);
    VariableType type;
    int int_value;
    double float_value;
    wchar_t *string_value = NULL;

    // Normalise les séparateurs décimaux (virgule à point)
    normalize_decimal_separator((wchar_t *)value);

    // Détermine le type de la valeur (entier, flottant, ou chaîne)
    if (swscanf(value, L"%d", &int_value) == 1 && wcschr(value, L'.') == NULL) {
        type = TYPE_INT;
    } else if (swscanf(value, L"%lf", &float_value) == 1) {
        type = TYPE_FLOAT;
    } else {
        type = TYPE_STRING;
        string_value = wcsdup(value);
    }

    // Vérifie le type si la variable existe déjà
    if (index != -1) {
        if (variables[index].type != type) {
            wprintf(L"Erreur : changement de type non autorisé pour la variable %ls\n", name);
            return 0;
        }
    } else { // Ajoute une nouvelle variable si elle n'existe pas encore
        if (variable_count >= MAX_VARIABLES) {
            wprintf(L"Erreur : nombre maximum de variables atteint.\n");
            return 0;
        }
        index = variable_count++;
        variables[index].name = wcsdup(name);
        variables[index].type = type;
    }

    // Affecte la valeur en fonction du type
    switch (type) {
        case TYPE_INT:
            variables[index].value.int_value = int_value;
            break;
        case TYPE_FLOAT:
            variables[index].value.float_value = float_value;
            break;
        case TYPE_STRING:
            if (variables[index].value.string_value) free(variables[index].value.string_value);
            variables[index].value.string_value = string_value;
            break;
    }

    // Confirmation de la définition de la variable
    wprintf(L"Variable %ls définie avec la valeur ", name);
    print_variable(&variables[index]);
    wprintf(L"\n");
    return 1;
}

// Récupère la valeur d'une variable, renvoie 1 si elle est définie, sinon 0
int get_variable(const wchar_t *name, Variable *result) {
    int index = find_variable(name);
    if (index == -1) {
        wprintf(L"Erreur : la variable %ls n'est pas définie\n", name);
        return 0;
    }
    *result = variables[index];
    return 1;
}

// Affiche une variable en fonction de son type
void print_variable(const Variable *var) {
    switch (var->type) {
        case TYPE_INT:
            wprintf(L"%d (entier)", var->value.int_value);
            break;
        case TYPE_FLOAT:
            wprintf(L"%.2f (réel)", var->value.float_value);
            break;
        case TYPE_STRING:
            wprintf(L"\"%ls\" (chaîne de caractères)", var->value.string_value);
            break;
    }
}
