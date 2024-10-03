def concat(chaine1, chaine2):
    # Concaténation de deux chaînes
    result = chaine1 + chaine2
    return result

def main():
    chaine1 = input("Saisissez la première chaîne de caractères : ")
    chaine2 = input("Saisissez la deuxième chaîne de caractères : ")
    concat_result = concat(chaine1, chaine2)
    print(f"Concaténation des deux chaînes : {concat_result}")

if __name__ == "__main__":
    main()
