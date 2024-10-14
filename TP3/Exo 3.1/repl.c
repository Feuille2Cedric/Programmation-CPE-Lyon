#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Traite la commande en fonction de son contenu
        if (strcmp(commande, "quit") == 0)
        {
            // Quitte le programme si la commande est "quit"
            printf("Arrêt...\n");
            continuer = 0;
        }
        else if (strncmp(commande, "echo ", 5) == 0)
        {
            // Traite la commande "echo" pour afficher du texte
            printf("Echo: ");

            // Imprime la chaîne
            for (int i = 5; commande[i] != '\0'; i++)
            {
                printf("%c", commande[i]);
            }
            printf("\n"); // Saut de ligne après la sortie
        }
        else if (strcmp(commande, "date") == 0)
        {
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
        else
        {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <text>' pour afficher du texte, ou tapez 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
