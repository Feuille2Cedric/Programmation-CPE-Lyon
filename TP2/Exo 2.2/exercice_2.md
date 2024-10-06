# Exercice 2.2 : Chaîne de Compilation (C)

## Introduction

Cet exercice couvre la chaîne de compilation en C, qui comprend les étapes du préprocesseur, de la compilation, de l'assemblage, de l'édition de liens et de l'exécution. Les optimisations de niveau 2 (`-O2`) et de niveau 3 (`-O3`) sont également abordées.

Deux exemples illustrent ces étapes :
1. Calcul de l'aire d'un cercle (`aire.c`)
2. Calcul de la surface et du volume d'une sphère à l'aide de plusieurs fichiers source (`sphere.h`, `surface.c`, `volume.c`, `main.c`).

---

## Exemple 1 : Calcul de l'Aire d'un Cercle (`aire.c`)

Le fichier `aire.c` calcule l'aire d'un cercle en utilisant la constante `M_PI` de la bibliothèque mathématique.

### Étapes de la Chaîne de Compilation

1. **Préprocesseur**  
   La commande suivante exécute le préprocesseur, traitant toutes les directives `#include` et macros :

```bash
gcc -E aire.c -o aire.i
```

2. **Compilation (Optimisation Niveau 2)**  
Le code est compilé en assembleur avec l'option `-O2` pour des optimisations standard :

```bash
gcc -O2 -S aire.i -o aire.s
```

3. **Assemblage**  
Le fichier assembleur est converti en fichier objet :

```bash
gcc -c aire.s -o aire.o
```

4. **Édition de liens**  
L'édition de liens combine le fichier objet avec les bibliothèques nécessaires, comme `math.h` :

```bash
gcc aire.o -lm -o aire
```

5. **Exécution**  
Le programme exécutable est lancé :

```bash
./aire
```


---

## Exemple 2 : Calcul de la Surface et du Volume d'une Sphère (`sphere.h`, `surface.c`, `volume.c`, `main.c`)

Un programme C utilisant plusieurs fichiers source pour calculer la surface et le volume d'une sphère.

### Étapes de la Chaîne de Compilation

1. **Préprocesseur**  
Chaque fichier source (`main.c`, `volume.c`, `surface.c`) est passé au préprocesseur :

```bash
gcc -E main.c -o main.i gcc -E volume.c -o volume.i gcc -E surface.c -o surface.i
```

2. **Compilation (Optimisation Niveau 3)**  
Les fichiers `.i` sont compilés en fichiers objets avec l'option `-O3` pour des optimisations plus agressives :

```bash
gcc -O3 -c main.i -o main.o gcc -O3 -c volume.i -o volume.o gcc -O3 -c surface.i -o surface.o
```

3. **Édition de liens**  
Les fichiers objets sont combinés pour former l'exécutable final :

```bash
gcc main.o volume.o surface.o -lm -o sphere
```

4. **Exécution**  
L'exécutable résultant est exécuté :

```bash
./sphere
```


---

## Notes sur les Optimisations

- **`-O2`** : Active des optimisations standard pour améliorer les performances tout en gardant un compromis acceptable entre la taille du code et la vitesse.
- **`-O3`** : Active des optimisations plus agressives, incluant des transformations de boucles, de fonctions, et des optimisations spécifiques qui peuvent améliorer les performances pour des programmes intensifs en calculs.

---

## Conclusion

La chaîne de compilation en C est composée de plusieurs étapes : préprocesseur, compilation, assemblage, édition de liens, et exécution. L'utilisation de différentes options de compilation (`-O2`, `-O3`) permet d'optimiser les performances du programme selon les besoins.

Ce processus de compilation peut être adapté selon la structure du projet, que celui-ci contienne un seul fichier source ou plusieurs fichiers répartis en modules.


