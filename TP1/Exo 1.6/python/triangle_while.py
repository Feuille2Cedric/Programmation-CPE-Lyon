def triangle(taille):
    # Validation pour vérifier que la taille est strictement inférieure à 10
    if taille >= 10:
        print("La taille doit être strictement inférieure à 10.")
        return
    
    i = 1

    # Boucle pour dessiner le triangle
    while i <= taille:
        line = ""
        j = 0
        while j < i:
            # Affichage des contours avec '*'
            if j == 0 or j == i - 1 or i == taille:
                line += "* "
            else:
                # Affichage de l'intérieur avec '#'
                line += "# "
            j += 1
        print(line.strip())
        i += 1

def main():
    taille = int(input("Entrez une valeur de taille de triangle inférieure à 10 : "))
    triangle(taille)

if __name__ == "__main__":
    main()