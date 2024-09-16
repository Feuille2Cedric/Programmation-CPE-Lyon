#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Déclaration et assignation des variables pour chaque type de données

    // Caractère signé et non signé
    char char_value = 'A';
    signed char signed_char_value = -50;
    unsigned char unsigned_char_value = 255;

    // Entiers courts
    short short_value = -32768;
    unsigned short unsigned_short_value = 65535;

    // Entiers
    int int_value = -2147483648;
    unsigned int unsigned_int_value = 4294967295;

    // Entiers longs
    long int long_int_value = -2147483647L;
    unsigned long int unsigned_long_int_value = 4294967295UL;

    // Entiers très longs
    long long int long_long_int_value = -9223372036854775807LL;
    unsigned long long int unsigned_long_long_int_value = 18446744073709551615ULL;

    // Nombres flottants
    float float_value = 3.14159f;
    double double_value = 2.718281828459;
    long double long_double_value = 1.618033988749895L;

    // Affichage des valeurs des variables
    printf("char_value : %c\n", char_value);
    printf("signed_char_value : %d\n", signed_char_value);
    printf("unsigned_char_value : %u\n", unsigned_char_value);

    printf("short_value : %d\n", short_value);
    printf("unsigned_short_value : %u\n", unsigned_short_value);

    printf("int_value : %d\n", int_value);
    printf("unsigned_int_value : %u\n", unsigned_int_value);

    printf("long_int_value : %ld\n", long_int_value);
    printf("unsigned_long_int_value : %lu\n", unsigned_long_int_value);

    printf("long_long_int_value : %lld\n", long_long_int_value);
    printf("unsigned_long_long_int_value : %llu\n", unsigned_long_long_int_value);

    printf("float_value : %f\n", float_value);
    printf("double_value : %lf\n", double_value);
    printf("long_double_value : %Lf\n", long_double_value);

    return 0;
}
