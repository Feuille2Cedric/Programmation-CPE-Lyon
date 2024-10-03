#include <stdio.h>

// Fonction qui calcule la longueur d'une chaîne
int longueur(char chaine[])
{
    int count = 0;
    while (chaine[count] != '\0') // Parcours de la chaîne jusqu'à trouver le caractère nul
    {
        count++;
    }
    return count; // Retourne la longueur de la chaîne
}

void carac(char chaine1[], char chaine2[])
{
    printf("Chaine 1 : %s (Longueur : %d)\n", chaine1, longueur(chaine1));
    printf("Chaine 2 : %s (Longueur : %d)\n", chaine2, longueur(chaine2));
}

int main()
{
    char chaine1[100]; // Allouer suffisamment de place pour la chaîne
    char chaine2[100]; // Allouer suffisamment de place pour la chaîne

    printf("Envoie la première chaine de caractères : ");
    scanf("%99s", chaine1); // Lire une chaîne de caractères jusqu'à 99 caractères

    printf("Envoie la deuxième chaine de caractères : ");
    scanf("%99s", chaine2); // Lire une chaîne de caractères jusqu'à 99 caractères

    carac(chaine1, chaine2);
    
    return 0;
}
