#include <stdio.h>
#include "sphere.h"

// Point d'entrée du programme
int main() {
    float rayon = 5.0;
    
    // Calculer la surface de la sphère
    float surface = calculer_surface(rayon);
    printf("La surface de la sphère de rayon %.2f est %.2f\n", rayon, surface);

    // Calculer le volume de la sphère
    float volume = calculer_volume(rayon);
    printf("Le volume de la sphère de rayon %.2f est %.2f\n", rayon, volume);

    return 0;
}

// Instructions de compilation :
// 1. Préprocessing :
//    $ gcc -E main.c -o main.i
// 2. Compilation avec optimisation de niveau 3 :
//    $ gcc -O3 -c main.i -o main.o
// 3. Édition de liens :
//    $ gcc main.o volume.o surface.o -lm -o sphere
// 4. Exécution :
//    $ ./sphere
