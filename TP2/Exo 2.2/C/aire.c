// Directive de préprocesseur pour inclure la bibliothèque mathématique
#include <math.h>  // Pour utiliser la constante M_PI

#include <stdio.h>

// Définition de la constante M_PI (valeur de π)
#define M_PI 3.14159265358979323846

// Fonction pour calculer l'aire d'un cercle
float calculer_aire(float rayon) {
    // Utilisation de la constante pi de la bibliothèque mathématique
    return M_PI * rayon * rayon;
}

// Point d'entrée du programme
int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon);
    // Affichage du résultat
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}

// Instructions de compilation avec optimisation de niveau 2 :
// 1. Préprocessing :
//    $ gcc -E aire.c -o aire.i
// 2. Compilation avec optimisation de niveau 2 :
//    $ gcc -O2 -S aire.i -o aire.s
// 3. Assemblage :
//    $ gcc -c aire.s -o aire.o
// 4. Édition de liens (avec l'option -lm pour la bibliothèque mathématique) :
//    $ gcc aire.o -lm -o aire
// 5. Exécution :
//    $ ./aire
