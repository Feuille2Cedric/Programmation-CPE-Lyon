def calcul(a, b):
    # Effectue diverses opérations arithmétiques sur a et b
    addition = a + b  # Addition de a et b
    soustraction = a - b  # Soustraction de b à a
    multiplication = a * b  # Multiplication de a par b
    division = a / b  # Division de a par b
    modulo = a % b  # Reste de la division de a par b
    egal = calcul_egal(a, b)  # Vérifie si a est égal à b
    sup = calcul_supperieur(a, b)  # Vérifie si a est supérieur à b

    # Affichage des résultats des opérations
    print("addition", addition)
    print("soustraction", soustraction)
    print("multiplication", multiplication)
    print("division", division)
    print("modulo", modulo)
    print("egal", egal)
    print("sup", sup)

def calcul_egal(a, b):
    # Vérifie si a est égal à b et retourne un booléen
    if a == b:
        return True
    else:
        return False
    
def calcul_supperieur(a, b):
    # Vérifie si a est supérieur à b et retourne un booléen
    if a > b:
        return True
    else:
        return False

def main():
    a = 16  # Variable a initialisée à 16
    b = 3  # Variable b initialisée à 3
    calcul(a, b)  # Appel de la fonction calcul pour effectuer les opérations

# Point d'entrée du programme
if __name__ == "__main__":
    main()
