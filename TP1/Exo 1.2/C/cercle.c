#include <stdio.h>
#include <math.h>

#define M_PI       3.14159265358979323846

int calcul_aire(float rayon)
{
    int aire = M_PI * rayon * rayon;

    printf("la valeur de l'aire est %d\n", aire);

    return 0;
}

int calcul_peri(float rayon)
{
    int peri = 2 * M_PI * rayon;

    printf("la valeur de l'aire est %d\n", peri);

    return 0;
}

int main()
{
    float rayon;
    printf("Entrez une valeur pour le rayon : ");
    while(scanf("%f",&rayon) != 1)
    {
        printf("Entrez une valeur pour le rayon : ");
        while(getchar() != '\n');
    }
    
    calcul_aire(rayon);
    calcul_peri(rayon);

    return 0;
}