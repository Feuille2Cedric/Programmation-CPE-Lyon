def triangle(taille):
    # Validation pour vérifier que la taille est strictement inférieure à 10
    if taille >= 10:
        print("La taille doit être strictement inférieure à 10.")
        return  # Sortie de la fonction si la taille n'est pas valide
    
    i = 1  # Initialisation de la variable de contrôle pour la boucle des lignes

    # Boucle pour dessiner le triangle
    while i <= taille:  # Parcourt chaque ligne du triangle
        line = ""  # Initialise la chaîne de caractères pour la ligne courante
        j = 0  # Initialisation de la variable de contrôle pour la boucle des colonnes
        while j < i:  # Parcourt chaque position dans la ligne courante
            # Affichage des contours avec '*'
            if j == 0 or j == i - 1 or i == taille:  # Premier ou dernier caractère de la ligne, ou si c'est la dernière ligne
                line += "* "  # Ajoute '*' à la chaîne de caractères
            else:
                # Affichage de l'intérieur avec '#'
                line += "# "  # Ajoute '#' pour les positions intérieures
            j += 1  # Incrémente la variable de colonne
        print(line.strip())  # Affiche la ligne courante en retirant les espaces supplémentaires à la fin
        i += 1  # Incrémente la variable de ligne

def main():
    # Demande à l'utilisateur d'entrer une taille pour le triangle
    taille = int(input("Entrez une valeur de taille de triangle inférieure à 10 : "))
    triangle(taille)  # Appelle la fonction pour dessiner le triangle

# Point d'entrée du programme
if __name__ == "__main__":
    main()
