#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// Type pour les fonctions de commande
typedef void (*fonction_commande)(char *commande);

// Structure pour représenter une commande
typedef struct {
    const char *nom;
    const char *description_fr;
    const char *description_en;
    fonction_commande fonction;
} Commande;

// Prototypes des fonctions de commande
void traiter_echo(char *commande);
void afficher_aide(char *commande);
void afficher_version(char *commande);
void afficher_date(char *commande);
void traiter_quit(char *commande);
const char* trouver_commande_proche(const char *saisie, int *en_francais); // Mise à jour ici
int commencer_par_chaine_sans_casse(const char *str, const char *prefix);

// Tableau des commandes en français et en anglais
Commande commandes[] = {
    {"echo", "afficher une ligne de texte", "display a line of text", traiter_echo},
    {"date", "afficher la date actuelle", "show actual date", afficher_date},
    {"version", "afficher la version de gcc", "show gcc version", afficher_version},
    {"aide", "afficher les commandes disponibles", "display help", afficher_aide},
    {"help", "afficher les commandes disponibles", "display help", afficher_aide},
    {"quit", "quitter le programme", "exit script", traiter_quit},
    {"quitter", "quitter le programme", "exit script", traiter_quit}
};

// Taille du tableau des commandes
int taille_commandes = sizeof(commandes) / sizeof(Commande);

// Fonction pour afficher la version de GCC
void afficher_version(char *commande)
{
    if (strcasecmp(commande, "version") == 0) {
        printf("GCC Version:\n");
    } else {
        printf("Version de GCC :\n");
    }
    system("gcc --version | head -n 1");
}

// Fonction pour afficher l'aide
void afficher_aide(char *commande)
{
    int en_francais = strcasecmp(commande, "aide") == 0;

    if (en_francais) {
        printf("Liste des commandes disponibles :\n");
    } else {
        printf("Available commands:\n");
    }

    for (int i = 0; i < taille_commandes; i++) {
        if ((en_francais && strcmp(commandes[i].nom, "aide") == 0) ||
            (!en_francais && strcmp(commandes[i].nom, "help") == 0) ||
            strcmp(commandes[i].nom, "echo") == 0 || strcmp(commandes[i].nom, "date") == 0 || strcmp(commandes[i].nom, "version") == 0 ||
            (en_francais && strcmp(commandes[i].nom, "quitter") == 0) || (!en_francais && strcmp(commandes[i].nom, "quit") == 0)) {
            
            printf("%s : %s\n", commandes[i].nom, en_francais ? commandes[i].description_fr : commandes[i].description_en);
        }
    }
}

// Fonction pour traiter la commande echo
void traiter_echo(char *commande)
{
    char *texte = commande + 5;
    while (*texte == ' ') {
        texte++;
    }

    if (strcasecmp(commande, "echo") == 0) {
        printf("%s\n", texte);
    } else {
        printf("Texte : %s\n", texte);
    }
}

// Fonction pour afficher la date
void afficher_date(char *commande)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (strcasecmp(commande, "date") == 0) {
        printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    } else {
        printf("Date actuelle : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
}

// Fonction pour quitter le programme
void traiter_quit(char *commande)
{
    if (strcasecmp(commande, "quit") == 0) {
        printf("Exiting program...\n");
    } else {
        printf("Arrêt du programme...\n");
    }
    exit(0);
}

// Fonction pour comparer les chaînes de caractères sans tenir compte de la casse
int comparer_chaine_sans_casse(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
            return 0;
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

// Calcul de la distance de Levenshtein pour suggérer une commande
int distance_levenshtein(const char *s1, const char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int d[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (tolower(s1[i - 1]) != tolower(s2[j - 1]));
            d[i][j] = ((d[i - 1][j] + 1) < (d[i][j - 1] + 1) ? (d[i - 1][j] + 1) : (d[i][j - 1] + 1));
            d[i][j] = ((d[i][j]) < (d[i - 1][j - 1] + cost) ? (d[i][j]) : (d[i - 1][j - 1] + cost));
        }
    }
    return d[len1][len2];
}

// Fonction pour trouver la commande la plus proche
const char* trouver_commande_proche(const char *saisie, int *en_francais) // Mise à jour ici aussi
{
    int distance_min = 100;
    const char *commande_proche = NULL;
    *en_francais = 0;

    for (int i = 0; i < taille_commandes; i++) {
        int distance = distance_levenshtein(saisie, commandes[i].nom);
        if (distance < distance_min) {
            distance_min = distance;
            commande_proche = commandes[i].nom;
            *en_francais = (strcmp(commandes[i].nom, "aide") == 0 || strcmp(commandes[i].nom, "quitter") == 0);
        }
    }
    return commande_proche;
}

// Vérifie si une commande commence par un préfixe (insensible à la casse)
int commencer_par_chaine_sans_casse(const char *str, const char *prefix)
{
    while (*prefix) {
        if (tolower((unsigned char)*str) != tolower((unsigned char)*prefix))
            return 0;
        str++;
        prefix++;
    }
    return *str == ' ' || *str == '\0';
}

int main()
{
    char commande[1024]; // Buffer pour stocker la commande utilisateur

    while (1)
    {
        printf("> ");
        if (!fgets(commande, sizeof(commande), stdin)) {
            printf("\nErreur de lecture de la commande.\n");
            continue;
        }

        commande[strcspn(commande, "\n")] = 0;

        int commande_trouvee = 0;

        if (commencer_par_chaine_sans_casse(commande, "echo")) {
            traiter_echo(commande);
            commande_trouvee = 1;
        } else {
            for (int i = 0; i < taille_commandes; i++) {
                if (comparer_chaine_sans_casse(commande, commandes[i].nom)) {
                    commandes[i].fonction(commande);
                    commande_trouvee = 1;
                    break;
                }
            }
        }

        if (!commande_trouvee)
        {
            int en_francais = 0;
            const char *suggestion = trouver_commande_proche(commande, &en_francais);

            if (en_francais) {
                printf("Commande non reconnue. Vouliez-vous dire '%s' ? Essayez 'aide' pour afficher la liste des commandes.\n", suggestion);
            } else {
                printf("Unrecognized command. Did you mean '%s'? Try 'help' to see the list of commands.\n", suggestion);
            }
        }

        printf("\n");
    }

    return 0;
}
