def copie(source):
    # Copie de la chaîne source dans une nouvelle chaîne
    destination = ''
    for char in source:
        destination += char
    return destination

def main():
    chaine = input("Saisissez une chaîne de caractères à copier : ")
    copie_chaine = copie(chaine)
    print(f"Copie de la chaîne : {copie_chaine}")

if __name__ == "__main__":
    main()
