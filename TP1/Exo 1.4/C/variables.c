#include <stdio.h>    // Inclusion de la bibliothèque standard pour les entrées/sorties
#include <limits.h>   // Inclusion de la bibliothèque pour obtenir les valeurs limites des types entiers
#include <float.h>    // Inclusion de la bibliothèque pour obtenir les valeurs limites des types flottants

int main() {
    // Déclaration et assignation des variables pour chaque type de données

    // Caractère signé et non signé
    char char_value = 'A';  // Caractère simple ASCII 'A'
    signed char signed_char_value = -50;  // Caractère signé (peut contenir des valeurs négatives)
    unsigned char unsigned_char_value = 255;  // Caractère non signé (valeurs positives uniquement)

    // Entiers courts
    short short_value = -32768;  // Entier court signé, limite inférieure
    unsigned short unsigned_short_value = 65535;  // Entier court non signé, valeur maximale

    // Entiers
    int int_value = -2147483648;  // Entier signé, limite inférieure (peut varier selon la plate-forme)
    unsigned int unsigned_int_value = 4294967295;  // Entier non signé, valeur maximale

    // Entiers longs
    long int long_int_value = -2147483647L;  // Entier long signé, valeur négative (suffixe 'L' pour long)
    unsigned long int unsigned_long_int_value = 4294967295UL;  // Entier long non signé (suffixe 'UL' pour unsigned long)

    // Entiers très longs
    long long int long_long_int_value = -9223372036854775807LL;  // Entier très long signé (suffixe 'LL' pour long long)
    unsigned long long int unsigned_long_long_int_value = 18446744073709551615ULL;  // Entier très long non signé (suffixe 'ULL' pour unsigned long long)

    // Nombres flottants
    float float_value = 3.14159f;  // Nombre flottant simple précision (suffixe 'f' pour float)
    double double_value = 2.718281828459;  // Nombre flottant double précision
    long double long_double_value = 1.618033988749895L;  // Nombre flottant double précision longue (suffixe 'L' pour long double)

    // Affichage des valeurs des variables
    printf("char_value : %c\n", char_value);  // Affiche le caractère
    printf("signed_char_value : %d\n", signed_char_value);  // Affiche le caractère signé comme un entier
    printf("unsigned_char_value : %u\n", unsigned_char_value);  // Affiche le caractère non signé comme un entier positif

    printf("short_value : %d\n", short_value);  // Affiche l'entier court signé
    printf("unsigned_short_value : %u\n", unsigned_short_value);  // Affiche l'entier court non signé

    printf("int_value : %d\n", int_value);  // Affiche l'entier signé
    printf("unsigned_int_value : %u\n", unsigned_int_value);  // Affiche l'entier non signé

    printf("long_int_value : %ld\n", long_int_value);  // Affiche l'entier long signé
    printf("unsigned_long_int_value : %lu\n", unsigned_long_int_value);  // Affiche l'entier long non signé

    printf("long_long_int_value : %lld\n", long_long_int_value);  // Affiche l'entier très long signé
    printf("unsigned_long_long_int_value : %llu\n", unsigned_long_long_int_value);  // Affiche l'entier très long non signé

    printf("float_value : %f\n", float_value);  // Affiche le nombre flottant simple précision
    printf("double_value : %lf\n", double_value);  // Affiche le nombre flottant double précision
    printf("long_double_value : %Lf\n", long_double_value);  // Affiche le nombre flottant double précision longue

    return 0;  // Retourne 0 pour indiquer la fin du programme
}
