# Scripts de manipulation de chaînes de caractères en Python et C

Ce projet comprend différents scripts en Python et en C permettant de manipuler des chaînes de caractères de diverses manières : concaténation, copie, calcul de longueur, et autres opérations de base.

## Bibliothèques utilisées

### C
* **`#include <stdio.h>`** : Fournit les fonctions d'entrée/sortie standard telles que `printf` et `scanf`.
* **`#include <math.h>`** : Fournit des fonctions mathématiques telles que `sqrt()`, `sin()`, `cos()`, et des constantes comme `M_PI` pour des calculs avancés.
* **`#include <stdlib.h>`** : Utilisé pour la gestion dynamique de la mémoire, les fonctions de conversion, et la génération de nombres aléatoires (`rand()`).
* **`#include <string.h>`** : Contient des fonctions pour manipuler les chaînes de caractères, comme `strcpy()`, `strstr()`, etc.

### Python
* **`import dis`** : Permet d'analyser le bytecode Python pour mieux comprendre comment une fonction est interprétée.
* **`import random`** : Génération de valeurs aléatoires (dans certains scripts).

## Références

### C
* [Documentation C sur cppreference.com](https://en.cppreference.com/w/c) : Référence pour les types de données, fonctions standard, et bonnes pratiques en C.
* [OpenClassrooms - Apprendre à programmer en C](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c) : Guide détaillé pour apprendre à programmer en C, de la syntaxe de base aux concepts plus avancés.
* [TutorialsPoint - C Programming](https://www.tutorialspoint.com/cprogramming/index.htm) : Tutoriels étape par étape pour apprendre le C, des bases aux concepts avancés.
* [Learn-C](https://www.learn-c.org/) : Un tutoriel interactif en ligne pour apprendre les concepts de base de C.
* [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) : Cours et tutoriels sur la programmation en C, incluant des exemples de code et des astuces pour apprendre le langage.
* [GeeksforGeeks - Structures in C](https://www.geeksforgeeks.org/structures-c/) : Tutoriel détaillé sur les structures (`struct`) en C et leur utilisation.
* [Programiz - C Structures](https://www.programiz.com/c-programming/c-structures) : Introduction aux structures en C, leur déclaration et leur utilisation.

### Python
* [Documentation Python officielle](https://docs.python.org/3/) : Référence principale pour les fonctions et méthodes utilisées dans les scripts (comme `input()`, `len()`, boucles `for`, etc.).
* [Tutoriels Python sur W3Schools](https://www.w3schools.com/python/) : Contient des tutoriels détaillés pour apprendre à manipuler les chaînes de caractères en Python.
* [OpenClassrooms - Apprendre à programmer en Python](https://openclassrooms.com/fr/courses/235344-apprenez-a-programmer-en-python) : Guide complet sur la programmation Python pour les débutants.
* [Real Python](https://realpython.com/) : Articles détaillés sur des sujets variés de Python, couvrant les bases et des concepts plus avancés.
* [GeeksforGeeks - Python Programming](https://www.geeksforgeeks.org/python-programming-language/) : Tutoriels pour apprendre les fondamentaux de Python.
* [Programiz - Python Classes and Objects](https://www.programiz.com/python-programming/class) : Introduction aux classes, objets, et programmation orientée objet en Python.
* [W3Schools - Python Classes/Objects](https://www.w3schools.com/python/python_classes.asp) : Tutoriel pour comprendre les bases des classes et des objets en Python.

## Difficulté
* **Concepts de base des chaînes de caractères** : Comprendre comment manipuler des chaînes en Python et C, notamment leur concaténation, leur copie, et le calcul de leur longueur, est essentiel pour bien maîtriser les opérations de base des deux langages.
* **Utilisation de boucles et structures conditionnelles** : Chaque script fait usage de boucles (`for`, `while`) pour parcourir les chaînes de caractères, ainsi que de structures conditionnelles (`if`, `else`) pour la logique de contrôle.
* **Découverte des classes (Python)** : Apprentissage des classes et de la programmation orientée objet en Python, en particulier la manière de créer des objets, de définir des méthodes, et d'utiliser des attributs.
* **Découverte des structures (C)** : En C, comprendre la définition et la manipulation des `struct` (structures) pour grouper différents types de données sous une même entité.
* **Optimisation avec les méthodes intégrées** : Bien que chaque opération (comme la concaténation ou le calcul de la longueur) puisse être réalisée manuellement, Python propose des méthodes intégrées telles que `+` pour la concaténation et `len()` pour la longueur des chaînes, qui sont plus performantes. En C, la connaissance des fonctions standards de `string.h` (comme `strcpy()`, `strcat()`, etc.) peut simplifier le travail.

## Commentaires
* **Simplicité des scripts** : Chaque script a été conçu pour être aussi simple et lisible que possible, facilitant la compréhension des manipulations de base des chaînes en Python et C.
* **Optimisation possible** : Des versions optimisées des scripts pourraient être réalisées en utilisant davantage les fonctionnalités intégrées de Python ou les fonctions de bibliothèque standard en C (`string.h`).
