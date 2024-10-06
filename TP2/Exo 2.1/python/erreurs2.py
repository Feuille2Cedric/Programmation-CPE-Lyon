from typing import List

def double_values(tableau: List[int]) -> None:
    # Parcourt chaque élément du tableau
    for compteur in range(len(tableau)):
        # Erreur : parfois multiplier par 3 au lieu de 2
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3

    return tableau

# Création d'un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appel de la fonction et stockage du résultat
resultat = double_values(tableau)

# Affichage du résultat final
print(resultat)

# Instructions pour le débogage :
# 1. Enregistrer le code dans un fichier `exercice_pdb.py`.
# 2. Ouvrir le terminal et exécuter :
#    $ python3 -m pdb exercice_pdb.py
# 3. Utiliser `l` pour lister les lignes de code autour de la ligne actuelle.
# 4. Utiliser `n` pour passer à la ligne suivante.
# 5. Placer un point d'arrêt avec `b <numéro_ligne>`, par exemple `b 5`.
# 6. Utiliser `c` pour continuer jusqu'au prochain point d'arrêt.
# 7. Utiliser `p tableau` pour afficher le contenu du tableau.
# 8. Utiliser `p compteur` pour afficher la valeur actuelle de compteur.
# 9. Identifier l'erreur (vérifier la condition dans la boucle) et la corriger.
# 10. Pour quitter le débogueur, utiliser `q`.
