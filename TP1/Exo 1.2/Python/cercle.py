# Import math Library
import math

def calcul_aire(rayon):
    pi = math.pi

    aire = pi * rayon * rayon

    print(f"\nL'aire est de {aire} cm !")

def calcul_perimetre(rayon):
    peri = 2 * math.pi * rayon

    print(f"Le périmètre est de {peri} cm !")

def main():
    rayon = int(input("Saisir une valeur de rayon pour le cercle : "))

    calcul_aire(rayon)
    calcul_perimetre(rayon)

if __name__ == "__main__":
    main()