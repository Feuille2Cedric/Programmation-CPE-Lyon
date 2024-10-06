#include <stdio.h>
#include <string.h>

// Définition de la longueur maximale d'une ligne
#define MAX_LINE_LENGTH 256 

int main() {
    char filename[100]; // Variable pour stocker le nom du fichier
    char phrase[100];   // Variable pour stocker la phrase à rechercher
    FILE *file;         // Pointeur vers le fichier
    char line[MAX_LINE_LENGTH]; // Variable pour stocker chaque ligne lue
    int line_number = 0; // Compteur de lignes
    int count;           // Compteur d'occurrences de la phrase dans une ligne

    // Demander à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier : ");
    scanf("%s", filename);

    // Demander à l'utilisateur de saisir la phrase à rechercher
    printf("Entrez la phrase à rechercher : ");
    scanf(" %[^\n]s", phrase); // Lit une phrase complète jusqu'à la nouvelle ligne

    // Ouvrir le fichier en lecture
    file = fopen(filename, "r");
    if (file == NULL) {
        // Si le fichier ne peut pas être ouvert, afficher une erreur
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 1; // Retourne 1 pour indiquer une erreur
    }

    // Lire le fichier ligne par ligne
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++; // Incrémenter le compteur de lignes
        count = 0;     // Réinitialiser le compteur d'occurrences pour chaque ligne

        // Compter le nombre de fois que la phrase apparaît dans la ligne
        char *ptr = line; // Pointeur pour parcourir la ligne
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            count++;                 // Incrémenter le compteur d'occurrences
            ptr += strlen(phrase);   // Avancer le pointeur pour rechercher la prochaine occurrence
        }

        // Afficher le résultat si la phrase est trouvée dans la ligne
        if (count > 0) {
            printf("Ligne %d : %d occurrence(s) de '%s'\n", line_number, count, phrase);
        }
    }

    // Fermer le fichier après la lecture
    fclose(file);
    return 0; // Retourne 0 pour indiquer que tout s'est bien passé
}
