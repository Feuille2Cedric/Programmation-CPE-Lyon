#include <stdio.h>
#include <stdbool.h>

// Déclaration des fonctions d'opérations
void calcul(int a, int b);
int calcul_egal(int a, int b);
int calcul_superieur(int a, int b);

int main() {
    int a = 16;
    int b = 3;

    // Appel de la fonction principale pour effectuer les calculs
    calcul(a, b);

    return 0;
}

void calcul(int a, int b) {
    int addition = a + b;
    int soustraction = a - b;
    int multiplication = a * b;
    int division = (b != 0) ? a / b : 0;  // Gestion de la division par zéro
    int modulo = (b != 0) ? a % b : 0;    // Gestion du modulo par zéro
    int egal = calcul_egal(a, b);
    int sup = calcul_superieur(a, b);

    // Affichage des résultats avec des spécificateurs corrects
    printf("Addition : %d\n", addition);
    printf("Soustraction : %d\n", soustraction);
    printf("Multiplication : %d\n", multiplication);
    printf("Division : %d\n", division);
    printf("Modulo : %d\n", modulo);
    printf("Egal : %s\n", egal ? "true" : "false");
    printf("Superieur : %s\n", sup ? "true" : "false");
}

int calcul_egal(int a, int b) {
    // Vérification d'égalité
    return a == b;
}

int calcul_superieur(int a, int b) {
    // Vérification si a est supérieur à b
    return a > b;
}
