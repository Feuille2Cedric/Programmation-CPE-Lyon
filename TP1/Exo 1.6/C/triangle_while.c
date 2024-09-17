#include <stdio.h>

void triangle(int taille)
{
    int i = 1;

    while (i <= taille)
    {
        int j = 0;
        while (j < i)
        {
            if (j == 0 || j == i - 1 || i == taille)
            {
                printf("* ");
            }
            else
            {
                printf("# ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

int main()
{
    int taille;
    
    // Demande à l'utilisateur de saisir une taille pour le triangle
    printf("Entrez une valeur pour la taille (strictement inférieure à 10) : ");
    while (scanf("%d", &taille) != 1 || taille >= 10 || taille < 1) {
        printf("Veuillez entrer un entier valide entre 1 et 9 : ");
        while (getchar() != '\n'); // Vider le buffer d'entrée
    }

    triangle(taille);

    return 0;
}