// variables.c
#include "variables.h"  // Inclusion pour les définitions de structures et constantes liées aux variables
#include <stdlib.h>     // Inclusion pour les fonctions d'allocation mémoire (ex. malloc, free)
#include <string.h>     // Inclusion pour les fonctions de manipulation de chaînes (ex. strdup)
#include <stdio.h>      // Inclusion pour les fonctions d'entrées/sorties de base (ex. printf)
#include <wchar.h>      // Inclusion pour la gestion des chaînes de caractères wide (ex. wcsdup, wprintf)

static Variable variables[MAX_VARIABLES]; // Tableau de stockage des variables définies
static int variable_count = 0;            // Compteur du nombre de variables actuellement définies

// Initialise la table des variables en réinitialisant le compteur de variables
void init_variables() {
    variable_count = 0;
}

// Remplace les virgules par des points dans une chaîne wide pour uniformiser les séparateurs décimaux
void normalize_decimal_separator(wchar_t *value) {
    for (int i = 0; value[i] != L'\0'; i++) {
        if (value[i] == L',') {
            value[i] = L'.';
        }
    }
}

// Recherche d'une variable par son nom ; retourne l'index ou -1 si la variable n'est pas trouvée
static int find_variable(const wchar_t *name) {
    for (int i = 0; i < variable_count; i++) {
        if (wcscmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int set_variable(const wchar_t *name, const wchar_t *value) {
    int index = find_variable(name);
    VariableType type;
    int int_value;
    double float_value;
    wchar_t *string_value = NULL;

    // Normalise le séparateur décimal (remplace les virgules par des points)
    normalize_decimal_separator((wchar_t *)value);

    // Détermine le type de la valeur (entier, flottant ou chaîne)
    if (swscanf(value, L"%d", &int_value) == 1 && wcschr(value, L'.') == NULL) {
        type = TYPE_INT;
    } else if (swscanf(value, L"%lf", &float_value) == 1) {
        type = TYPE_FLOAT;
    } else {
        type = TYPE_STRING;
        string_value = wcsdup(value);
    }

    // Si la variable existe déjà, vérifie que le type est cohérent
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

    // Assigne la valeur en fonction du type détecté
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

    // Affiche une confirmation de la définition de la variable
    wprintf(L"Variable %ls définie avec la valeur ", name);
    print_variable(&variables[index]);
    wprintf(L"\n");
    return 1;
}

// Récupère la valeur d'une variable et la stocke dans `result`, renvoie 1 si elle est trouvée, sinon 0
int get_variable(const wchar_t *name, Variable *result) {
    int index = find_variable(name);
    if (index == -1) {
        return 0; // Supprime l'affichage direct de l'erreur ici
    }
    *result = variables[index];
    return 1;
}

// Affiche une variable selon son type (entier, flottant, ou chaîne de caractères)
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
