def calcul4():
    # Boucle pour les nombres de 1 à 1000 inclus
    for i in range(1, 1001):
        # Vérifie si i est divisible par 4 mais pas par 6
        if i % 4 == 0 and i % 6 != 0:
            print(i, "est divisible par 4 mais pas par 6")

def calcul_5_7():
    # Boucle pour les nombres de 1 à 1000 inclus
    for i in range(1, 1001):
        # Première méthode : Vérifie si i est divisible par 5 ou 7, mais pas par 10
        # if (i % 5 == 0 or i % 7 == 0) and i % 10 != 0:
        #     print(i, "est divisible par 5 ou par 7 mais pas par 10")

        # Deuxième méthode : Vérifie séparément pour 5 et 7
        if i % 5 == 0 and i % 10 != 0:
            print(i, "est divisible par 5 mais pas par 10")
        elif i % 7 == 0 and i % 10 != 0:
            print(i, "est divisible par 7 mais pas par 10")

def calcul_pair_8():
    # Boucle pour les nombres de 1 à 1000 inclus
    for i in range(1, 1001):
        # Vérifie si i est divisible par 8
        if i % 8 == 0:
            print(i, "est divisible par 8")

def main():
    # Appel des fonctions pour effectuer les calculs
    calcul4()
    calcul_5_7()
    calcul_pair_8()

# Point d'entrée du programme
if __name__ == "__main__":
    main()
