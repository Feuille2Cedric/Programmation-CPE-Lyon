#include <stdio.h>
#include <math.h> // Inclusion des bibliothèques standard nécessaires

// Définition de la constante M_PI (valeur de π)
#define M_PI 3.14159265358979323846

// Fonction qui calcule l'aire d'un cercle à partir de son rayon
int calcul_aire(float rayon)
{
    // Calcul de l'aire : π * rayon²
    int aire = M_PI * rayon * rayon;

    // Affichage de l'aire calculée
    printf("La valeur de l'aire est %d\n", aire);

    return 0; // Retourne 0 (signifiant la fin de l'exécution correcte de la fonction)
}

// Fonction qui calcule le périmètre (ou circonférence) d'un cercle à partir de son rayon
int calcul_peri(float rayon)
{
    // Calcul du périmètre : 2 * π * rayon
    int peri = 2 * M_PI * rayon;

    // Affichage du périmètre calculé
    printf("La valeur du périmètre est %d\n", peri);

    return 0; // Retourne 0 (signifiant la fin de l'exécution correcte de la fonction)
}

// Fonction principale (point d'entrée du programme)
int main()
{
    float rayon; // Déclaration de la variable pour stocker le rayon
    printf("Entrez une valeur pour le rayon : ");
    
    // Boucle pour s'assurer que l'utilisateur entre une valeur valide
    while(scanf("%f",&rayon) != 1)
    {
        printf("Entrez une valeur pour le rayon : ");
        // Vide le buffer d'entrée pour éviter une boucle infinie en cas d'entrée invalide
        while(getchar() != '\n');
    }
    
    // Appel de la fonction pour calculer et afficher l'aire
    calcul_aire(rayon);
    // Appel de la fonction pour calculer et afficher le périmètre
    calcul_peri(rayon
