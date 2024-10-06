#include <stdio.h>
#include <string.h>

// Définition de la structure pour stocker les informations d'un étudiant
struct Etudiant 
{
    char Nom[50];
    char Prenom[50];
    char Adresse[100];
    float Note[2];
};

// Fonction pour ajouter les informations d'un étudiant
void ajouterEtudiant(struct Etudiant *etudiant) {
    char buffer[100];

    // Lecture et copie du nom
    printf("Nom : ");
    scanf("%s", buffer);
    strcpy(etudiant->Nom, buffer); // Utilisation de strcpy pour copier le nom

    // Lecture et copie du prénom
    printf("Prénom : ");
    scanf("%s", buffer);
    strcpy(etudiant->Prenom, buffer); // Utilisation de strcpy pour copier le prénom

    // Lecture et copie de l'adresse
    printf("Adresse : ");
    getchar(); // Consomme le caractère '\n' laissé par scanf
    fgets(buffer, 100, stdin); // Lecture de l'adresse (qui peut contenir des espaces)
    buffer[strcspn(buffer, "\n")] = 0; // Supprime le caractère '\n' en fin de chaîne
    strcpy(etudiant->Adresse, buffer); // Utilisation de strcpy pour copier l'adresse

    // Lecture des notes
    printf("Note 1 : ");
    scanf("%f", &etudiant->Note[0]);

    printf("Note 2 : ");
    scanf("%f", &etudiant->Note[1]);
}

// Fonction pour afficher les informations d'un étudiant
void afficherEtudiant(struct Etudiant etudiant)
{
    printf("Nom : %s\n", etudiant.Nom);
    printf("Prénom : %s\n", etudiant.Prenom);
    printf("Adresse : %s\n", etudiant.Adresse);
    printf("Note 1 : %.2f\n", etudiant.Note[0]);
    printf("Note 2 : %.2f\n", etudiant.Note[1]);
}

int main()
{
    struct Etudiant etudiants[5]; // Tableau de 5 étudiants

    // Ajout des informations pour 5 étudiants
    for (int i = 0; i < 5; i++)
    {
        printf("Étudiant %d :\n", i + 1);
        ajouterEtudiant(&etudiants[i]);
        printf("\n");
    }
    
    // Affichage des informations pour chaque étudiant
    printf("Informations des étudiants :\n\n");
    for (int j = 0; j < 5; j++)
    {
        printf("Étudiant %d :\n", j + 1);
        afficherEtudiant(etudiants[j]);
        printf("\n");
    }
    
    return 0;
}
