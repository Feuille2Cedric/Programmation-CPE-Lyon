def main():
    # Demander à l'utilisateur de saisir le nom du fichier
    filename = input("Entrez le nom du fichier : ")
    
    # Demander à l'utilisateur de saisir la phrase à rechercher
    phrase = input("Entrez la phrase à rechercher : ")
    
    try:
        # Ouvrir le fichier et lire son contenu
        with open(filename, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        # Initialiser le numéro de ligne
        line_number = 0
        
        # Rechercher la phrase
        for line in lines:
            line_number += 1
            count = line.count(phrase)  # Compter le nombre d'occurrences de la phrase

            # Afficher le résultat si la phrase est trouvée
            if count > 0:
                print(f"Ligne {line_number} : {count} occurrence(s) de '{phrase}'")

    except FileNotFoundError:
        print("Erreur : impossible d'ouvrir le fichier.")

if __name__ == "__main__":
    main()
