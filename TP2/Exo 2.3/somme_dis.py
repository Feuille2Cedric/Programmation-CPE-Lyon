import dis

# Fonction pour calculer la somme des entiers de 0 à n-1
def calculer_somme(n: int) -> int:
    somme = 0
    # Boucle for pour parcourir tous les entiers de 0 à n-1
    for i in range(n):
        somme += i
    return somme

def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()

"""
Instructions d'analyse du bytecode :

1. La fonction `calculer_somme` est analysée par `dis.dis`.
   Voici le bytecode généré pour la boucle for :
   
   - **LOAD_CONST** : Charge une constante sur la pile, ici `0` pour initialiser `somme`.
   - **STORE_FAST** : Stocke la valeur en haut de la pile dans une variable locale (ici `somme`).

   - **GET_ITER** : Crée un itérateur pour l'objet `range(n)`.
   - **FOR_ITER** : Obtient le prochain élément de l'itérateur ; si aucun élément n'est disponible, il saute à la fin de la boucle.
   - **STORE_FAST** : Stocke la valeur de l'élément actuel de la boucle `for` dans `i`.
   
   - **LOAD_FAST** : Charge `somme` et `i` sur la pile pour l'addition.
   - **INPLACE_ADD** : Ajoute `i` à `somme`.
   - **STORE_FAST** : Stocke le nouveau résultat de `somme`.

   - **JUMP_ABSOLUTE** : Retourne au début de la boucle pour la prochaine itération.

   - **RETURN_VALUE** : Retourne la valeur finale de `somme`.

2. Voici les instructions spécifiques liées à la gestion de la boucle :
   - **GET_ITER** : Transforme `range(n)` en un itérateur.
   - **FOR_ITER** : Récupère le prochain élément de l'itérateur et gère la fin de la boucle.
   - **SETUP_LOOP** et **POP_BLOCK** : Préparent la boucle et retirent la boucle de la pile de contrôle à la fin.

3. Remplacer la boucle for par une boucle while :
"""

# Version modifiée de `calculer_somme` avec une boucle while
def calculer_somme_while(n: int) -> int:
    somme = 0
    i = 0
    # Boucle while pour parcourir les entiers de 0 à n-1
    while i < n:
        somme += i
        i += 1
    return somme

# Analyse du bytecode de la version modifiée
dis.dis(calculer_somme_while)

"""
Comparaison des boucles for et while dans le bytecode :

1. La boucle `while` utilise des instructions différentes pour contrôler le flux :
   - **LOAD_FAST** : Charge `i` et `n` sur la pile pour la comparaison.
   - **COMPARE_OP** : Effectue la comparaison `i < n`.
   - **POP_JUMP_IF_FALSE** : Saute à la fin de la boucle si la comparaison échoue.
   - **LOAD_FAST** : Charge `somme` et `i` sur la pile pour l'addition.
   - **INPLACE_ADD** : Ajoute `i` à `somme`.
   - **STORE_FAST** : Stocke le nouveau résultat de `somme`.
   - **LOAD_FAST** / **INPLACE_ADD** : Incrémente `i`.
   - **JUMP_ABSOLUTE** : Retourne au début de la boucle `while` pour la prochaine itération.

2. Contrairement à la boucle `for`, la boucle `while` utilise une combinaison explicite de comparaison et de saut conditionnel pour contrôler les itérations.

Observations :
- La boucle `for` utilise un itérateur et des instructions comme **GET_ITER** et **FOR_ITER** pour gérer les éléments de l'itération.
- La boucle `while` utilise une logique conditionnelle explicite pour contrôler la boucle, avec **COMPARE_OP** et **POP_JUMP_IF_FALSE** pour décider si elle doit continuer ou non.

Conclusion :
- Le bytecode de la boucle `for` est généralement plus compact et optimisé pour des itérations simples sur des objets itérables.
- La boucle `while` offre un contrôle plus granulaire sur la condition de boucle, mais cela peut entraîner un bytecode légèrement plus complexe.
"""
