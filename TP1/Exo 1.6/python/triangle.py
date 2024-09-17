from math import *

def triangle(taille):
    # for i in range(1, taille + 1):
    #     print("* " * i)

    # Validation pour vérifier que la taille est strictement inférieure à 10
    if taille >= 10:
        print("La taille doit être strictement inférieure à 10.")
        return
    
    # Boucle pour dessiner le triangle
    for i in range(1, taille + 1):
        line = ""
        for j in range(i):
            # Affichage des contours avec '*'
            if j == 0 or j == i - 1 or i == taille:
                line += "* "
            else:
                # Affichage de l'intérieur avec '#'
                line += "# "
        print(line.strip())

def main():
    taille = int(input("Entrez une valeur de taille de triangle inférieure à 10 : "))
    triangle(taille)

if __name__ == "__main__":
    main()