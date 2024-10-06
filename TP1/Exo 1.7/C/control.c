#include <stdio.h>  // Inclusion de la bibliothèque standard pour les entrées/sorties

// Fonction pour trouver les nombres divisibles par 4 mais pas par 6
void calcul4()
{
    // Boucle de 1 à 1000
    for (int i = 1; i <= 1000; i++) 
    {
        // Vérifie si i est divisible par 4 mais pas par 6
        if (i % 4 == 0 && i % 6 != 0)
            printf("\n%d est divisible par 4 mais pas par 6", i);
    }
}

// Fonction pour trouver les nombres divisibles par 5 ou 7 mais pas par 10
void calcul_5_7()
{
    // Boucle de 1 à 1000
    for (int i = 1; i <= 1000; i++)
    {
        // Vérifie si i est divisible par 5 mais pas par 10
        if (i % 5 == 0 && i % 10 != 0)
            printf("\n%d est divisible par 5 mais pas par 10", i);
        // Vérifie si i est divisible par 7 mais pas par 10
        else if (i % 7 == 0 && i % 10 != 0)
            printf("\n%d est divisible par 7 mais pas par 10", i);
    }
    printf("\n");  // Saut de ligne après la boucle
}

// Fonction pour trouver les nombres divisibles par 8
void calcul_pair_8()
{
    // Boucle de 1 à 1000
    for (int i = 1; i <= 1000; i++)
    {
        // Vérifie si i est divisible par 8
        if (i % 8 == 0)
        {
            printf("\n%d est divisible par 8", i);
        }
    }
}

int main()
{
    // Appel de chaque fonction pour effectuer les calculs
    calcul4();
    calcul_5_7(); 
    calcul_pair_8();

    return 0;  // Fin du programme
}
