import random

class Couleur:
    def __init__(self, R, G, B, A):
        self.R = R
        self.G = G
        self.B = B
        self.A = A

    def __eq__(self, other):
        return (self.R == other.R and
                self.G == other.G and
                self.B == other.B and
                self.A == other.A)

    def __hash__(self):
        return hash((self.R, self.G, self.B, self.A))

def main():
    # Créer une liste de 100 instances de Couleur
    couleurs = [Couleur(random.randint(0, 255), random.randint(0, 255),
                        random.randint(0, 255), 255) for _ in range(100)]
    
    # Utiliser un dictionnaire pour stocker les couleurs distinctes et leur nombre d'occurrences
    occurrences = {}

    for couleur in couleurs:
        if couleur in occurrences:
            occurrences[couleur] += 1
        else:
            occurrences[couleur] = 1

    # Afficher les résultats
    print("Couleurs distinctes et occurrences :")
    for couleur, count in occurrences.items():
        print(f"Couleur : (R: {couleur.R}, G: {couleur.G}, B: {couleur.B}, A: {couleur.A}) - {count} occurrence(s)")

if __name__ == "__main__":
    main()
