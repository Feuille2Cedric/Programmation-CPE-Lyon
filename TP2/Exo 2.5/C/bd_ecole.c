#include <stdio.h>
#include <string.h>

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

    printf("Nom : ");
    scanf("%s", buffer);
    strcpy(etudiant->Nom, buffer); // Utilisation de strcpy pour copier le nom

    printf("Prénom : ");
    scanf("%s", buffer);
    strcpy(etudiant->Prenom, buffer); // Utilisation de strcpy pour copier le prénom

    printf("Adresse : ");
    getchar(); // Consomme le caractère '\n' laissé par scanf
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Supprime le '\n'
    strcpy(etudiant->Adresse, buffer); // Utilisation de strcpy pour copier l'adresse

    printf("Note 1 : ");
    scanf("%f", &etudiant->Note[0]);

    printf("Note 2 : ");
    scanf("%f", &etudiant->Note[1]);
}

int afficherEtudiant(struct Etudiant etudiant)
{
    printf("Nom : %s", etudiant.Nom);
    printf("Nom : %s", etudiant.Prenom);
    printf("Nom : %s", etudiant.Adresse);
    printf("Nom : %.2f", etudiant.Note[0]);
    printf("Nom : %.2f", etudiant.Note[1]);
}

int main()
{
    struct Etudiant etudiant[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Étudiant %d :\n", i + 1);
        ajouterEtudiant(&etudiant[i]);
        printf("\n");
    }
    
    for (int j = 0; j < 5; j++)
    {
        printf("Étudiant %d :\n", j + 1);
        afficherEtudiant(etudiant[j]);
        printf("\n");
    }
    
    return 0;
}