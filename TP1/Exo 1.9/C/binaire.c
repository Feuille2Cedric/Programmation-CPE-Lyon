#include <stdio.h>

#define MAX_BITS 32  // Taille maximale pour un entier 32 bits

// Fonction pour convertir un entier en binaire
void int_to_binary(int n, char bits[]) {
    int index = 0;  // Index pour parcourir le tableau de bits

    // Si n est 0, retourner directement "0"
    if (n == 0) {
        bits[index++] = '0';  // Ajouter '0' dans le tableau
        bits[index] = '\0';  // Ajouter le caractère de fin de chaîne
        return;  // Fin de la fonction
    }

    // Remplir le tableau avec les bits de n
    while (n > 0) {
        bits[index++] = (n % 2) + '0';  // Ajouter le bit de poids faible (0 ou 1 sous forme de caractère)
        n /= 2;  // Décale n vers la droite (division par 2)
    }

    bits[index] = '\0';  // Ajouter le caractère de fin de chaîne

    // Inverser la chaîne pour obtenir la bonne représentation binaire
    for (int i = 0; i < index / 2; i++) {
        // Échange les éléments pour inverser la chaîne
        char temp = bits[i];
        bits[i] = bits[index - i - 1];
        bits[index - i - 1] = temp;
    }
}

int main() {

    int n;
    // Lecture de l'entrée utilisateur
    printf("Entrez un nombre : ");
    scanf("%d", &n);

    char bits[MAX_BITS + 1];  // Tableau pour stocker la chaîne binaire (32 + 1 pour le caractère de fin de chaîne)

    // Conversion de l'entier en chaîne binaire
    int_to_binary(n, bits);

    // Affichage du résultat
    printf("Représentation binaire de %d : %s\n", n, bits);

    return 0;  // Fin du programme
}
