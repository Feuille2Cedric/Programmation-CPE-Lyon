# calculs.py

def calculer(a, b, op):
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
            if b == 0:
                raise ValueError("Erreur : Division par zéro")
            return a % b
        else:
            # Gestion de l'opérateur non reconnu
            raise ValueError(f"Erreur : Opérateur non reconnu '{op}'")
    except ValueError as e:
        return str(e)

def main():
    # Lecture des entrées utilisateur
    try:
        a = float(input("Entrez le premier nombre : "))
        b = float(input("Entrez le second nombre : "))
        op = input("Entrez l'opérateur (+, -, *, /, %) : ")

        # Calcul et affichage du résultat
        resultat = calculer(a, b, op)
        print(f"Le résultat de {a} {op} {b} est : {resultat}")

    except ValueError as e:
        print(f"Erreur de saisie : {e}")

if __name__ == "__main__":
    main()
