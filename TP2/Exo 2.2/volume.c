#include "sphere.h"

// Fonction pour calculer le volume de la sphère
float calculer_volume(float rayon) {
    // Formule : (4/3) * pi * r^3
    return (4.0/3.0) * M_PI * rayon * rayon * rayon;
}

// Instructions de compilation :
// 1. Préprocessing :
//    $ gcc -E volume.c -o volume.i
// 2. Compilation avec optimisation de niveau 3 :
//    $ gcc -O3 -c volume.i -o volume.o
