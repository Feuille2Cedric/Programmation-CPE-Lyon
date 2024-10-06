# calculs.py

def calculer(a, b, op):
    # Fonction pour effectuer des calculs de base
    try:
        # Utilisation de if-elif pour déterminer l'opération à effectuer
        if op == '+':
            return a + b
        elif op == '-':
            return a - b
        elif op == '*':
            return a * b
        elif op == '/':
            # Gestion de la division par zéro
            if b == 0:
                raise ValueError("Erreur : Division par zéro")
            return a / b
        elif op == '%':
            # Gestion de la division par zéro
            if b == 0:
                raise ValueError("Erreur : Division par zéro")
            return a % b
        else:
            # Gestion de l'opérateur non reconnu
            raise ValueError(f"Erreur : Opérateur non reconnu '{op}'")
    except ValueError as e:
        # Capture des erreurs de type ValueError et retourne le message d'erreur
        return str(e)

def main():
    # Lecture des entrées utilisateur
    try:
        a = float(input("Entrez le premier nombre : "))  # Lecture du premier nombre
        b = float(input("Entrez le second nombre : "))   # Lecture du second nombre
        op = input("Entrez l'opérateur (+, -, *, /, %) : ")  # Lecture de l'opérateur

        # Calcul et affichage du résultat
        resultat = calculer(a, b, op)
        print(f"Le résultat de {a} {op} {b} est : {resultat}")

    except ValueError as e:
        # Gestion des erreurs lors de la saisie des nombres
        print(f"Erreur de saisie : {e}")

# Point d'entrée du programme
if __name__ == "__main__":
    main()
