# Importation de la bibliothèque math pour utiliser des fonctions mathématiques, notamment pi
import math

# Fonction qui calcule l'aire d'un cercle en fonction de son rayon
def calcul_aire(rayon):
    # Récupération de la valeur de pi depuis la bibliothèque math
    pi = math.pi
    
    # Calcul de l'aire : π * rayon²
    aire = pi * rayon * rayon

    # Affichage de l'aire calculée, formatée avec une précision adéquate
    print(f"\nL'aire est de {aire} cm² !")

# Fonction qui calcule le périmètre (ou circonférence) d'un cercle en fonction de son rayon
def calcul_perimetre(rayon):
    # Calcul du périmètre : 2 * π * rayon
    peri = 2 * math.pi * rayon

    # Affichage du périmètre calculé, formaté avec une précision adéquate
    print(f"Le périmètre est de {peri} cm !")

# Fonction principale pour démarrer le programme
def main():
    # Demande à l'utilisateur de saisir une valeur pour le rayon du cercle, en la convertissant en entier
    rayon = int(input("Saisir une valeur de rayon pour le cercle : "))

    # Appel de la fonction pour calculer et afficher l'aire
    calcul_aire(rayon)
    # Appel de la fonction pour calculer et afficher le périmètre
    calcul_perimetre(rayon)

# Point d'entrée du programme
if __name__ == "__main__":
    main()
