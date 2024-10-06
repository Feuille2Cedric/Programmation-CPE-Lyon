#include <stdio.h> // Inclusion de la bibliothèque standard pour les entrées/sorties

// Fonction pour afficher la taille des différents types de données
int sizeoftype()
{
    // Déclaration de variables de différents types
    char chaine[50 + 10]; // Tableau de 60 caractères (50 + 10)
    short yihaaaa = -42; // Entier court (short) initialisé à -42
    int entier = 42; // Entier (int) initialisé à 42
    long int longdefou = 42000000; // Entier long (long int) initialisé à 42000000
    long long int gravelong = 4200000000000000000; // Entier long long (long long int) initialisé à une grande valeur
    float floa = 42.0; // Nombre flottant (float) initialisé à 42.0
    double foisdeux = 42.0; // Nombre flottant double précision (double) initialisé à 42.0
    long double deuxfoisdeux = 42.0; // Nombre flottant double précision longue (long double) initialisé à 42.0

    // Affichage de la taille en mémoire de chaque type de données
    // Utilisation de "%zu" pour afficher les tailles, car sizeof() retourne un type `size_t`
    printf("Taille d'un char (char) : %zu octets\n", sizeof(chaine));
    printf("Taille d'un short (short) : %zu octets\n", sizeof(yihaaaa));
    printf("Taille d'un entier (int) : %zu octets\n", sizeof(entier));
    printf("Taille d'un long entier (long int) : %zu octets\n", sizeof(longdefou));
    printf("Taille d'un long long entier (long long int) : %zu octets\n", sizeof(gravelong));
    printf("Taille d'un flottant (float) : %zu octets\n", sizeof(floa));
    printf("Taille d'un double (double) : %zu octets\n", sizeof(foisdeux));
    printf("Taille d'un long double (long double) : %zu octets\n", sizeof(deuxfoisdeux));
}

// Fonction principale (point d'entrée du programme)
int main()
{
    // Appel de la fonction pour afficher les tailles des différents types de données
    sizeoftype();
    
    return 0; // Fin du programme
}
