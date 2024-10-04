#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 100
#define MAX_UNIQUE_COLORS 100

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
} Couleur;

typedef struct {
    Couleur couleur;
    int count;
} CouleurDistincte;

int couleur_est_egale(Couleur c1, Couleur c2) {
    return (c1.R == c2.R && c1.G == c2.G && c1.B == c2.B && c1.A == c2.A);
}

int main() {
    Couleur couleurs[MAX_COLORS];
    CouleurDistincte distinctes[MAX_UNIQUE_COLORS];
    int unique_count = 0;

    // Initialiser le tableau de couleurs
    for (int i = 0; i < MAX_COLORS; i++) {
        couleurs[i].R = rand() % 256; // Valeurs aléatoires entre 0 et 255
        couleurs[i].G = rand() % 256;
        couleurs[i].B = rand() % 256;
        couleurs[i].A = 255; // Alpha à 255 (opaque)
    }

    // Compter les occurrences des couleurs
    for (int i = 0; i < MAX_COLORS; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (couleur_est_egale(couleurs[i], distinctes[j].couleur)) {
                distinctes[j].count++;
                found = 1;
                break;
            }
        }
        if (!found && unique_count < MAX_UNIQUE_COLORS) {
            distinctes[unique_count].couleur = couleurs[i];
            distinctes[unique_count].count = 1;
            unique_count++;
        }
    }

    // Afficher les résultats
    printf("Couleurs distinctes et occurrences :\n");
    for (int i = 0; i < unique_count; i++) {
        printf("Couleur %d : (R: %d, G: %d, B: %d, A: %d) - %d occurrence(s)\n",
               i + 1, distinctes[i].couleur.R, distinctes[i].couleur.G,
               distinctes[i].couleur.B, distinctes[i].couleur.A,
               distinctes[i].count);
    }

    return 0;
}
