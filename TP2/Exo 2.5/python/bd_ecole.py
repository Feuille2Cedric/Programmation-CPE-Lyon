# Classe Etudiant
class Etudiant:
    def __init__(self, nom, prenom, adresse, note1, note2):
        # Initialisation des attributs de la classe
        self.Nom = nom
        self.Prenom = prenom
        self.Adresse = adresse
        # Les notes sont stockées sous forme de liste de float
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
    note1 = float(input("Note 1 : "))  # Lecture de la première note
    note2 = float(input("Note 2 : "))  # Lecture de la deuxième note

    # Retourne une nouvelle instance de la classe Etudiant
    return Etudiant(nom, prenom, adresse, note1, note2)

def main():
    etudiants = []  # Liste pour stocker les instances de la classe Etudiant

    # Ajout de 5 étudiants
    for i in range(5):
        print(f"\nÉtudiant {i + 1}:")
        etudiant = ajouterEtudiant()  # Création d'un nouvel étudiant
        etudiants.append(etudiant)  # Ajout de l'étudiant à la liste

    # Affichage des informations des étudiants
    print("\nInformations des étudiants :\n")
    for etudiant in etudiants:
        etudiant.afficherEtudiant()  # Appel de la méthode pour afficher les détails de chaque étudiant
        print()  # Ligne vide pour séparer les informations des étudiants

# Point d'entrée du programme
if __name__ == "__main__":
    main()
