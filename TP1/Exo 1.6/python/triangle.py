def triangle(taille):
    # Validation pour vérifier que la taille est strictement inférieure à 10
    if taille >= 10:
        print("La taille doit être strictement inférieure à 10.")
        return  # Arrête la fonction si la condition n'est pas remplie
    
    # Boucle pour dessiner le triangle
    for i in range(1, taille + 1):  # Parcourt chaque ligne du triangle
        line = ""  # Initialisation de la ligne à afficher
        for j in range(i):  # Parcourt chaque position dans la ligne courante
            # Affichage des contours avec '*'
            if j == 0 or j == i - 1 or i == taille:  # Premier ou dernier caractère de la ligne, ou si c'est la dernière ligne
                line += "* "  # Ajoute '*' à la ligne
            else:
                # Affichage de l'intérieur avec '#'
                line += "# "  # Ajoute '#' à la ligne pour les positions intérieures
        print(line.strip())  # Affiche la ligne en supprimant les espaces supplémentaires à la fin

def main():
    # Demande à l'utilisateur d'entrer une taille pour le triangle
    taille = int(input("Entrez une valeur de taille de triangle inférieure à 10 : "))
    # Appelle la fonction triangle avec la taille donnée
    triangle(taille)

# Point d'entrée du programme
if __name__ == "__main__":
    main()
