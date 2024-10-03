def longueur(chaine):
    # Calcul de la longueur de la chaîne
    count = 0
    for char in chaine:
        count += 1
    return count

def main():
    chaine = input("Saisissez une chaîne de caractères : ")
    print(f"Longueur de la chaîne : {longueur(chaine)}")

if __name__ == "__main__":
    main()
