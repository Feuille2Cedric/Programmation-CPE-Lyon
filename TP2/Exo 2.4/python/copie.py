def copie(source):
    # Copie de la chaîne source dans une nouvelle chaîne
    destination = ''  # Initialisation d'une chaîne vide pour la copie
    for char in source:
        destination += char  # Ajoute chaque caractère de la source à la destination
    return destination

def main():
    # Demande à l'utilisateur de saisir une chaîne de caractères
    chaine = input("Saisissez une chaîne de caractères à copier : ")
    
    # Copie la chaîne en utilisant la fonction copie()
    copie_chaine = copie(chaine)
    
    # Affiche la copie de la chaîne
    print(f"Copie de la chaîne : {copie_chaine}")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
