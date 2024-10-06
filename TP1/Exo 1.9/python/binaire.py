# Fonction pour convertir un entier en binaire
def entier_en_binaire(n):
    # Cas particulier : si l'entier est 0, retourne directement "0"
    if n == 0:
        return "0"
    
    bits = []  # Liste pour stocker les bits
    # Boucle pour extraire les bits de poids faible à poids fort
    while n > 0:
        bits.append(str(n % 2))  # Ajoute le bit de poids faible (reste de la division par 2) à la liste
        n //= 2  # Division entière de n par 2 (équivaut à un décalage binaire vers la droite)
    
    # Inverse la liste pour obtenir la bonne représentation binaire
    bits.reverse()
    return ''.join(bits)  # Retourne les bits concaténés en une seule chaîne

def main():
    # Lecture d'un nombre entier de l'utilisateur
    try:
        n = int(input("Entrez un nombre entier : "))  # Convertit l'entrée utilisateur en un entier
        bin = entier_en_binaire(n)  # Convertit l'entier en binaire
        print(f"La représentation binaire de {n} est : {bin}")  # Affiche la représentation binaire
    
    except ValueError as e:
        # Gestion d'erreur si l'utilisateur entre une valeur non-entière
        print(f"Erreur : Veuillez entrer un nombre entier valide. Détails : {e}")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
