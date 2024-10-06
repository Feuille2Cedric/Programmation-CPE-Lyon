from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    # Parcourt chaque élément du tableau
    for compteur in range(len(tableau)):
        # Erreur : parfois multiplier par 3 au lieu de 2
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3
        # Insère un point d'arrêt pour observer le tableau
        pdb.set_trace()

    return tableau

# Création d'un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appel de la fonction et stockage du résultat
resultat = double_values(tableau)

# Affichage du résultat final
print(resultat)

# Instructions pour le débogage :
# 1. Exécuter le script Python normalement :
#    $ python3 erreurs1.py
# 2. Utiliser `n` pour passer à la ligne suivante.
# 3. Utiliser `p tableau` pour afficher le contenu du tableau à chaque étape.
# 4. Utiliser `p compteur` pour afficher la valeur actuelle de compteur.
# 5. Observer pourquoi certains éléments du tableau sont multipliés par 3.
# 6. Corriger l'erreur (vérifier la condition dans la boucle).
# 7. Pour quitter le débogueur, utiliser `q`.
