# Fonction pour convertir un entier en binaire
def entier_en_binaire(n):
    if n == 0:
        return "0"
    
    bits = []
    while n > 0:
        bits.append(str(n % 2))  # Ajoute le bit de poids faible
        n //= 2  # Décale vers la droite
    
    # Inverse la liste pour obtenir la représentation correcte
    bits.reverse()
    return ''.join(bits)

def main():
    # Lecture d'un nombre entier de l'utilisateur
    try:
        n = int(input("Entrez un nombre entier : "))
        bin = entier_en_binaire(n)
        print(f"La représentation binaire de {n} est : {bin}")
    
    except ValueError as e:
        print(f"Erreur : Veuillez entrer un nombre entier valide. Détails : {e}")

if __name__ == "__main__":
    main()
