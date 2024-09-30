#include <stdio.h>

// Fonction principale
int main() {
    int num1, num2, result;
    char op;

    // Lecture des entrées utilisateur
    printf("Entrez le premier nombre : ");
    scanf("%d", &num1);
    printf("Entrez le second nombre : ");
    scanf("%d", &num2);
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    // Utilisation de switch pour déterminer l'opération
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Erreur : Division par zéro\n");
            } else {
                result = num1 / num2;
                printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            }
            break;
        case '%':
            if (num2 == 0) {
                printf("Erreur : Division par zéro\n");
            } else {
                result = num1 % num2;
                printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            }
            break;
        case '&':
            result = num1 & num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '|':
            result = num1 | num2;
            printf("Résultat de %d %c %d = %d\n", num1, op, num2, result);
            break;
        case '~':
            // Opération NOT sur num1 seulement
            result = ~num1;
            printf("Résultat de ~%d = %d\n", num1, result);
            break;
        default:
            printf("Erreur : Opérateur non reconnu '%c'\n", op);
            break;
    }

    return 0;
}
