import math

# Fonction pour calculer l'aire d'un cercle
def calculer_aire(rayon: float) -> float:
    return math.pi * rayon * rayon  # Utilise la constante pi et calcule l'aire

# Fonction principale pour tester la fonction calculer_aire
def main() -> None:
    rayon: float = 5.0  # Rayon du cercle
    aire: float = calculer_aire(rayon)  # Calcul de l'aire
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    main()
