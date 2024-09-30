#include <stdio.h>

#define MAX_BITS 32  // Taille maximale pour un entier 32 bits

void int_to_binary(int n, char bits[]) {
    int index = 0;

    // Si n est 0, retourner directement "0"
    if (n == 0) {
        bits[index++] = '0';
        bits[index] = '\0';
        return;
    }

    // Remplir le tableau avec les bits de n
    while (n > 0) {
        bits[index++] = (n % 2) + '0';  // Ajouter le bit de poids faible
        n /= 2;  // Décale vers la droite
    }

    bits[index] = '\0';  // Ajouter le caractère de fin de chaîne

    // Inverser la chaîne pour obtenir la bonne représentation binaire
    for (int i = 0; i < index / 2; i++) {
        char temp = bits[i];
        bits[i] = bits[index - i - 1];
        bits[index - i - 1] = temp;
    }
}

int main() {

    int n;
    // Lecture des entrées utilisateur
    printf("Entrez un nombre : ");
    scanf("%d", &n);

    char bits[MAX_BITS + 1];  // Tableau pour stocker la chaîne binaire (32 + 1)

    int_to_binary(n, bits);

    printf("Représentation binaire de %d : %s\n", n, bits);

    return 0;
}