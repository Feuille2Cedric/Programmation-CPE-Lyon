def concat(chaine1, chaine2):
    # Concaténation de deux chaînes
    result = chaine1 + chaine2  # Combine les deux chaînes
    return result

def main():
    # Demander à l'utilisateur de saisir deux chaînes de caractères
    chaine1 = input("Saisissez la première chaîne de caractères : ")
    chaine2 = input("Saisissez la deuxième chaîne de caractères : ")
    
    # Concaténer les deux chaînes
    concat_result = concat(chaine1, chaine2)
    
    # Afficher le résultat de la concaténation
    print(f"Concaténation des deux chaînes : {concat_result}")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
