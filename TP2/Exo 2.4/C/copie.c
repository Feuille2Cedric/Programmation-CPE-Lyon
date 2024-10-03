#include <stdio.h>

// Fonction qui copie la chaîne source dans la chaîne destination
void copie(char destination[], char source[])
{
    int i = 0;
    // Parcourt chaque caractère de la source jusqu'au caractère nul
    while (source[i] != '\0')
    {
        destination[i] = source[i]; // Copie chaque caractère
        i++;
    }
    destination[i] = '\0'; // Ajoute le caractère nul à la fin de la destination
}

int main()
{
    char source[100];      // Allouer suffisamment de place pour la chaîne source
    char destination[100]; // Allouer suffisamment de place pour la chaîne destination

    printf("Envoie la chaîne source : ");
    scanf("%99s", source); // Lire une chaîne de caractères jusqu'à 99 caractères

    copie(destination, source); // Copier la chaîne source dans la destination

    printf("La chaîne copiée est : %s\n", destination); // Afficher la chaîne copiée
    
    return 0;
}
