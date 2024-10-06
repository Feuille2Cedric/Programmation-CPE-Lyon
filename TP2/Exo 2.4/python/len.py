def longueur(chaine):
    # Calcul de la longueur de la chaîne
    count = 0  # Initialise un compteur à 0
    for char in chaine:
        count += 1  # Incrémente le compteur pour chaque caractère dans la chaîne
    return count  # Retourne la longueur totale de la chaîne

def main():
    # Demande à l'utilisateur de saisir une chaîne de caractères
    chaine = input("Saisissez une chaîne de caractères : ")
    
    # Affiche la longueur de la chaîne en utilisant la fonction longueur()
    print(f"Longueur de la chaîne : {longueur(chaine)}")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
