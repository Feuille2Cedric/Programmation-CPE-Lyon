#include <stdio.h>

int main() {
    // Déclaration d'un tableau de taille 100
    int tableau[100];

    // Erreur ici : sizeof(tableau) retourne la taille en octets, pas le nombre d'éléments.
    // La boucle dépasse la taille réelle du tableau.
    for (int compteur = 0; compteur < sizeof(tableau); compteur++) { // Erreur
        tableau[compteur] = tableau[compteur] * 2;
    }

    return (0);
}

// Instructions de débogage :
// 1. Compiler le fichier avec des informations de débogage :
//    $ gcc -ggdb3 erreurs.c
// 2. Exécuter le programme dans gdb :
//    $ gdb a.out
// 3. Dans gdb, utiliser la commande `r` pour exécuter le programme.
//    Observer l'erreur de dépassement de pile.
// 4. Utiliser `bt` pour afficher la pile d'appels et trouver la ligne de l'erreur.
// 5. Placer un point d'arrêt à la ligne concernée, par exemple :
//    (gdb) break erreurs.c:10
// 6. Réexécuter avec `r` et inspecter les valeurs des variables avec `p tableau[compteur]`.
