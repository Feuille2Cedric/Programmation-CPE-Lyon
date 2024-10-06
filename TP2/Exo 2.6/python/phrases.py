def main():
    # Demander à l'utilisateur de saisir le nom du fichier
    filename = input("Entrez le nom du fichier : ")
    
    # Demander à l'utilisateur de saisir la phrase à rechercher
    phrase = input("Entrez la phrase à rechercher : ")
    
    try:
        # Ouvrir le fichier et lire son contenu
        with open(filename, 'r', encoding='utf-8') as file:
            lines = file.readlines()  # Lire toutes les lignes du fichier dans une liste

        # Initialiser le numéro de ligne
        line_number = 0
        
        # Rechercher la phrase dans chaque ligne
        for line in lines:
            line_number += 1  # Incrémenter le compteur de ligne
            count = line.count(phrase)  # Compter le nombre d'occurrences de la phrase dans la ligne

            # Afficher le résultat si la phrase est trouvée dans la ligne
            if count > 0:
                print(f"Ligne {line_number} : {count} occurrence(s) de '{phrase}'")

    # Gestion de l'erreur si le fichier n'est pas trouvé
    except FileNotFoundError:
        print("Erreur : impossible d'ouvrir le fichier.")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
