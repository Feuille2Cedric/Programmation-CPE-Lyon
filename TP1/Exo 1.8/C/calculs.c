#include <stdio.h> // Inclusion de la bibliothèque standard pour les entrées/sorties

// Fonction principale
int main() {
    int num1, num2, result; // Déclaration de variables pour stocker les deux nombres et le résultat
    char op; // Variable pour stocker l'opérateur

    // Lecture des entrées utilisateur
    printf("Entrez le premier nombre : ");
    scanf("%d", &num1); // Lecture du premier entier
    printf("Entrez le second nombre : ");
    scanf("%d", &num2); // Lecture du second entier
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op); // Lecture de l'opérateur (le caractère `%` est échappé par `%%` dans scanf)

    // Utilisation d'un switch pour déterminer l'opération en fonction de l'opérateur
    switch (op) {
        case '+':
            // Addition
            result = num1 + num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '-':
            // Soustraction
            result = num1 - num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '*':
            // Multiplication
            result = num1 * num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '/':
            // Division
            if (num2 == 0) {
                // Gestion de la division par zéro
                printf("Erreur : Division par zéro\n");
            } else {
                result = num1 / num2;
                printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            }
            break;
        case '%':
            // Modulo (reste de la division)
            if (num2 == 0) {
                // Gestion de la division par zéro
                printf("Erreur : Division par zéro\n");
            } else {
                result = num1 % num2;
                printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            }
            break;
        case '&':
            // Opération AND bit à bit
            result = num1 & num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '|':
            // Opération OR bit à bit
            result = num1 | num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '~':
            // Opération NOT bit à bit sur num1 seulement (num2 est ignoré)
            result = ~num1;
            printf("Résultat de ~%d = %d\n", num1, result);
            break;
        default:
            // Gestion d'un opérateur non reconnu
            printf("Erreur : Opérateur non reconnu '%c'\n", op);
            break;
    }

    return 0; // Fin du programme
}
