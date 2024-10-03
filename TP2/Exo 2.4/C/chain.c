#include <stdio.h>

// Fonction qui calcule la longueur d'une chaîne
int longueur(char chaine[])
{
    int count = 0;
    while (chaine[count] != '\0') // Parcourt la chaîne jusqu'à trouver le caractère nul
    {
        count++;
    }
    return count; // Retourne la longueur de la chaîne
}

// Fonction qui copie la chaîne source dans la chaîne destination
void copie(char destination[], char source[])
{
    int i = 0;
    while (source[i] != '\0') // Copie chaque caractère de la source dans la destination
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Ajoute le caractère nul à la fin de la destination
}

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

int main()
{
    char chaine1[100]; // Allouer suffisamment de place pour la chaîne 1
    char chaine2[100]; // Allouer suffisamment de place pour la chaîne 2
    char copie_chaine1[100]; // Stocker la copie de chaîne 1
    char concat_result[200]; // Stocker le résultat de la concaténation

    // Demander à l'utilisateur de saisir les deux chaînes
    printf("Envoie la première chaîne de caractères : ");
    scanf("%99s", chaine1); // Lire une chaîne de caractères jusqu'à 99 caractères

    printf("Envoie la deuxième chaîne de caractères : ");
    scanf("%99s", chaine2); // Lire une chaîne de caractères jusqu'à 99 caractères

    // Calculer et afficher la longueur de chaque chaîne
    printf("Longueur de la première chaîne : %d\n", longueur(chaine1));
    printf("Longueur de la deuxième chaîne : %d\n", longueur(chaine2));

    // Copier la première chaîne et afficher le résultat
    copie(copie_chaine1, chaine1);
    printf("Copie de la première chaîne : %s\n", copie_chaine1);

    // Concaténer les deux chaînes et afficher le résultat
    // Initialiser concat_result avec chaine1
    copie(concat_result, chaine1);
    concat(concat_result, chaine2);
    printf("Concaténation des deux chaînes : %s\n", concat_result);

    return 0;
}
