#include <stdio.h>

int sizeoftype()
{
    char chaine[50 + 10];
    short yihaaaa = -42;
    int entier = 42;
    long int longdefou = 42000000;
    long long int gravelong = 4200000000000000000;
    float floa = 42.0;
    double foisdeux = 42.0;
    long double deuxfoisdeux = 42.0;
    

    printf("Taille d'un char (char) : %zu\n", sizeof(chaine));
    printf("Taille d'un short (short) : %zu\n", sizeof(yihaaaa));
    printf("Taille d'un entier (int) : %zu\n", sizeof(entier));
    printf("Taille d'un long entier (long int) : %zu\n", sizeof(longdefou));
    printf("Taille d'un long long entier (long long int) : %zu\n", sizeof(gravelong));
    printf("Taille d'un flotant (float) : %zu\n", sizeof(floa));
    printf("Taille d'un double (double) : %zu\n", sizeof(foisdeux));
    printf("Taille d'un long double (long double) : %zu\n", sizeof(deuxfoisdeux));
}

int main()
{    
    sizeoftype();
    
    return 0;
}