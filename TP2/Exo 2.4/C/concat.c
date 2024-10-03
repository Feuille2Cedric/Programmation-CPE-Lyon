#include <stdio.h>

// Fonction qui concatène la chaîne source à la fin de la chaîne destination
void concat(char destination[], char source[])
{
    int i = 0, j = 0;

    // Trouve la fin de la chaîne destination
    while (destination[i] != '\0')
    {
        i++;
    }

    // Copie les caractères de la source à partir de la fin de la destination
    while (source[j] != '\0')
    {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0'; // Ajoute le caractère nul à la fin de la destination
}

void carac(char destination[], char source[])
{
    concat(destination, source); // Concaténer la source dans la destination
    printf("Chaine finale : %s\n", destination); // Affiche la chaîne finale complète
}

int main()
{
    char chaine1[200]; // Allouer suffisamment de place pour la chaîne finale
    char chaine2[100]; // Allouer suffisamment de place pour la chaîne source

    printf("Envoie la première chaine de caractères (Destination) : ");
    scanf("%199s", chaine1); // Lire une chaîne de caractères jusqu'à 199 caractères

    printf("Envoie la deuxième chaine de caractères (Source) : ");
    scanf("%99s", chaine2); // Lire une chaîne de caractères jusqu'à 99 caractères

    carac(chaine1, chaine2); // Appeler la fonction pour concaténer les chaînes
    
    return 0;
}
