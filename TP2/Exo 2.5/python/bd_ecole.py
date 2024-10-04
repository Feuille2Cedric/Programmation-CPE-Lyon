class Etudiant:
    def __init__(self, nom, prenom, adresse, note1, note2):
        self.Nom = nom
        self.Prenom = prenom
        self.Adresse = adresse
        self.Notes = [float(note1), float(note2)]

    # Méthode pour afficher les détails de l'étudiant
    def afficherEtudiant(self):
        print(f"Nom : {self.Nom}")
        print(f"Prénom : {self.Prenom}")
        print(f"Adresse : {self.Adresse}")
        print(f"Note 1 : {self.Notes[0]}")
        print(f"Note 2 : {self.Notes[1]}")

# Fonction pour ajouter un nouvel étudiant
def ajouterEtudiant():
    print(f"Saisissez les informations de l'étudiant :")
    nom = input("Nom : ")
    prenom = input("Prénom : ")
    adresse = input("Adresse : ")
    note1 = float(input("Note 1 : "))
    note2 = float(input("Note 2 : "))

    # Retourne une nouvelle instance de la classe Etudiant
    return Etudiant(nom, prenom, adresse, note1, note2)

def main():
    etudiants = []

    # Ajout de 5 étudiants
    for i in range(5):
        print(f"\nÉtudiant {i + 1}:")
        etudiant = ajouterEtudiant()
        etudiants.append(etudiant)

    # Affichage des informations des étudiants
    print("\nInformations des étudiants :\n")
    for etudiant in etudiants:
        etudiant.afficherEtudiant()
        print()

if __name__ == "__main__":
    main()
