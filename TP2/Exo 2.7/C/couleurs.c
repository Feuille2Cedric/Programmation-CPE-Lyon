#include <stdio.h>
#include <stdlib.h>

// Nombre total de couleurs générées
#define MAX_COLORS 100
// Nombre maximal de couleurs uniques possibles
#define MAX_UNIQUE_COLORS 100

// Structure pour représenter une couleur avec ses composantes RGBA
typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
} Couleur;

// Structure pour représenter une couleur unique et son compteur d'occurrences
typedef struct {
    Couleur couleur;
    int count;
} CouleurDistincte;

// Fonction pour vérifier si deux couleurs sont identiques
int couleur_est_egale(Couleur c1, Couleur c2) {
    return (c1.R == c2.R && c1.G == c2.G && c1.B == c2.B && c1.A == c2.A);
}

int main() {
    Couleur couleurs[MAX_COLORS];                // Tableau pour stocker les couleurs générées
    CouleurDistincte distinctes[MAX_UNIQUE_COLORS];  // Tableau pour stocker les couleurs uniques et leurs occurrences
    int unique_count = 0;                        // Compteur pour les couleurs uniques trouvées

    // Initialiser le tableau de couleurs avec des valeurs aléatoires
    for (int i = 0; i < MAX_COLORS; i++) {
        couleurs[i].R = rand() % 256; // Valeurs aléatoires entre 0 et 255 pour le rouge
        couleurs[i].G = rand() % 256; // Valeurs aléatoires entre 0 et 255 pour le vert
        couleurs[i].B = rand() % 256; // Valeurs aléatoires entre 0 et 255 pour le bleu
        couleurs[i].A = 255;          // Valeur fixe à 255 pour l'opacité (opaque)
    }

    // Compter les occurrences de chaque couleur dans le tableau
    for (int i = 0; i < MAX_COLORS; i++) {
        int found = 0;  // Indique si la couleur a déjà été trouvée dans les couleurs uniques

        // Comparer la couleur actuelle avec toutes les couleurs uniques trouvées jusqu'à présent
        for (int j = 0; j < unique_count; j++) {
            if (couleur_est_egale(couleurs[i], distinctes[j].couleur)) {
                // Si la couleur est déjà présente, incrémenter son compteur d'occurrences
                distinctes[j].count++;
                found = 1;  // Marque la couleur comme trouvée
                break;
            }
        }
        // Si la couleur n'est pas trouvée et que le nombre de couleurs uniques n'a pas atteint la limite
        if (!found && unique_count < MAX_UNIQUE_COLORS) {
            // Ajouter la nouvelle couleur à la liste des couleurs uniques
            distinctes[unique_count].couleur = couleurs[i];
            distinctes[unique_count].count = 1;  // Initialiser le compteur d'occurrences à 1
            unique_count++;
        }
    }

    // Afficher les résultats des couleurs uniques et leurs occurrences
    printf("Couleurs distinctes et occurrences :\n
