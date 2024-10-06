#include <stdio.h> // Inclusion de la bibliothèque standard pour les entrées/sorties

// Fonction pour dessiner un triangle
void triangle(int taille)
{
    int i = 1;  // Initialisation de la variable de contrôle de la boucle pour les lignes

    // Boucle pour chaque ligne du triangle, de 1 à la taille donnée
    while (i <= taille)
    {
        int j = 0;  // Initialisation de la variable de contrôle de la boucle pour les colonnes
        // Boucle pour chaque caractère à afficher sur la ligne i
        while (j < i)
        {
            // Conditions pour savoir quand afficher un "*" ou un "#"
            if (j == 0 || j == i - 1 || i == taille)
            {
                printf("* ");  // Affiche "*" si on est sur la bordure du triangle ou sur la dernière ligne
            }
            else
            {
                printf("# ");  // Affiche "#" si on est à l'intérieur du triangle, sans bordure
            }
            j++;  // Incrémente la variable de colonne
        }
        printf("\n");  // Nouvelle ligne pour passer à la ligne suivante du triangle
        i++;  // Incrémente la variable de ligne
    }
}

int main()
{
    int taille;

    // Demande à l'utilisateur de saisir une taille pour le triangle
    printf("Entrez une valeur pour la taille (strictement inférieure à 10) : ");
    // Vérifie que l'utilisateur entre un entier valide entre 1 et 9
    while (scanf("%d", &taille) != 1 || taille >= 10 || taille < 1) {
        printf("Veuillez entrer un entier valide entre 1 et 9 : ");
        while (getchar() != '\n'); // Vide le buffer d'entrée en cas d'entrée non valide
    }

    // Appelle la fonction triangle pour dessiner le triangle de la taille donnée
    triangle(taille);

    return 0; // Fin du programme
}
