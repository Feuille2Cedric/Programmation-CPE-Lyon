def longueur(chaine):
    # Calcul de la longueur de la chaîne
    count = 0
    for char in chaine:
        count += 1
    return count

def copie(source):
    # Copie de la chaîne source dans une nouvelle chaîne
    destination = ''
    for char in source:
        destination += char
    return destination

def concat(chaine1, chaine2):
    # Concaténation de deux chaînes
    result = chaine1 + chaine2
    return result

def main():
    # Demander à l'utilisateur de saisir deux chaînes de caractères
    chaine1 = input("Envoie la première chaîne de caractères : ")
    chaine2 = input("Envoie la deuxième chaîne de caractères : ")
    
    # Calcul de la longueur de chaque chaîne
    print(f"Longueur de la première chaîne : {longueur(chaine1)}")
    print(f"Longueur de la deuxième chaîne : {longueur(chaine2)}")
    
    # Copie de la première chaîne
    copie_chaine1 = copie(chaine1)
    print(f"Copie de la première chaîne : {copie_chaine1}")
    
    # Concaténation des deux chaînes
    concat_result = concat(chaine1, chaine2)
    print(f"Concaténation des deux chaînes : {concat_result}")

if __name__ == "__main__":
    main()
