#include <stdio.h>  // Inclusion de la bibliothèque standard pour les entrées/sorties
#include <stdbool.h>  // Inclusion de la bibliothèque pour utiliser le type booléen (bool, true, false)

// Déclaration des fonctions d'opérations
void calcul(int a, int b);
int calcul_egal(int a, int b);
int calcul_superieur(int a, int b);

int main() {
    int a = 16;  // Initialisation de la variable a
    int b = 3;   // Initialisation de la variable b

    // Appel de la fonction principale pour effectuer les calculs
    calcul(a, b);

    return 0;  // Fin du programme
}

// Fonction calcul qui effectue plusieurs opérations mathématiques et affiche les résultats
void calcul(int a, int b) {
    // Opérations arithmétiques de base
    int addition = a + b;  // Addition de a et b
    int soustraction = a - b;  // Soustraction de b à a
    int multiplication = a * b;  // Multiplication de a par b
    int division = (b != 0) ? a / b : 0;  // Gestion de la division par zéro, retourne 0 si b est 0
    int modulo = (b != 0) ? a % b : 0;  // Gestion du modulo par zéro, retourne 0 si b est 0
    int egal = calcul_egal(a, b);  // Vérifie si a est égal à b
    int sup = calcul_superieur(a, b);  // Vérifie si a est supérieur à b

    // Affichage des résultats avec des spécificateurs corrects
    printf("Addition : %d\n", addition);
    printf("Soustraction : %d\n", soustraction);
    printf("Multiplication : %d\n", multiplication);
    printf("Division : %d\n", division);
    printf("Modulo : %d\n", modulo);
    printf("Egal : %s\n", egal ? "true" : "false");  // Affiche "true" si égalité, sinon "false"
    printf("Superieur : %s\n", sup ? "true" : "false");  // Affiche "true" si a est supérieur à b, sinon "false"
}

// Fonction calcul_egal pour vérifier si deux entiers sont égaux
int calcul_egal(int a, int b) {
    // Vérification d'égalité
    return a == b;  // Retourne 1 si a est égal à b, sinon 0
}

// Fonction calcul_superieur pour vérifier si a est supérieur à b
int calcul_superieur(int a, int b) {
    // Vérification si a est supérieur à b
    return a > b;  // Retourne 1 si a est supérieur à b, sinon 0
}
