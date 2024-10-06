import random

# Classe pour représenter une couleur avec des composantes RGBA
class Couleur:
    def __init__(self, R, G, B, A):
        # Initialise les composantes de la couleur : Rouge, Vert, Bleu, Alpha (transparence)
        self.R = R
        self.G = G
        self.B = B
        self.A = A

    # Méthode pour comparer deux instances de Couleur
    def __eq__(self, other):
        # Compare chaque composante (R, G, B, A) pour déterminer si les deux couleurs sont identiques
        return (self.R == other.R and
                self.G == other.G and
                self.B == other.B and
                self.A == other.A)

    # Méthode pour obtenir un hachage unique pour chaque instance de Couleur
    def __hash__(self):
        # Crée une valeur de hachage basée sur les composantes RGBA
        return hash((self.R, self.G, self.B, self.A))

def main():
    # Créer une liste de 100 instances de Couleur avec des valeurs aléatoires pour R, G, B et A=255
    couleurs = [Couleur(random.randint(0, 255), random.randint(0, 255),
                        random.randint(0, 255), 255) for _ in range(100)]
    
    # Utiliser un dictionnaire pour stocker les couleurs distinctes et leur nombre d'occurrences
    occurrences = {}

    for couleur in couleurs:
        # Vérifie si la couleur est déjà dans le dictionnaire
        if couleur in occurrences:
            occurrences[couleur] += 1  # Incrémente le compteur si la couleur existe déjà
        else:
            occurrences[couleur] = 1   # Initialise le compteur à 1 si la couleur est nouvelle

    # Afficher les résultats
    print("Couleurs distinctes et occurrences :")
    for couleur, count in occurrences.items():
        print(f"Couleur : (R: {couleur.R}, G: {couleur.G}, B: {couleur.B}, A: {couleur.A}) - {count} occurrence(s)")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
