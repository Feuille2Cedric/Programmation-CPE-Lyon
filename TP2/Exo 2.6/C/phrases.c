#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    char filename[100];
    char phrase[100];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int count;

    // Demander à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier : ");
    scanf("%s", filename);

    // Demander à l'utilisateur de saisir la phrase à rechercher
    printf("Entrez la phrase à rechercher : ");
    scanf(" %[^\n]s", phrase);

    // Ouvrir le fichier
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Lire le fichier ligne par ligne
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        count = 0;

        // Compter le nombre de fois que la phrase apparaît dans la ligne
        char *ptr = line;
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            count++;
            ptr += strlen(phrase); // Avancer le pointeur
        }

        // Afficher le résultat si la phrase est trouvée
        if (count > 0) {
            printf("Ligne %d : %d occurrence(s) de '%s'\n", line_number, count, phrase);
        }
    }

    // Fermer le fichier
    fclose(file);
    return 0;
}
