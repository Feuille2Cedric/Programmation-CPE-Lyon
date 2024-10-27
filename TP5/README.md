# Scripts de Manipulation de Chaînes de Caractères et d'Évaluation d'Expressions Arithmétiques en C

Ce projet comprend différents scripts en Python et en C permettant de manipuler des chaînes de caractères de diverses manières : concaténation, copie, calcul de longueur, et autres opérations de base. Il inclut également un interpréteur en langage C avec des fonctionnalités avancées pour la gestion des variables et l’évaluation d'expressions lambda. Ce projet se concentre sur le développement de structures de données et d'algorithmes permettant de gérer des variables, de parser et d'évaluer des expressions mathématiques, en intégrant ces fonctionnalités dans un interpréteur de commandes interactif.

## Bibliothèques utilisées

### C
* **`#include <stdio.h>`** : Fournit les fonctions d'entrée/sortie standard, telles que `printf` pour l'affichage, `scanf` pour la lecture de l'entrée, et des fonctions pour la manipulation de fichiers (`fopen`, `fclose`, etc.).
* **`#include <string.h>`** : Contient des fonctions pour manipuler des chaînes de caractères, comme `strcpy` pour la copie, `strcat` pour la concaténation, et `strlen` pour calculer la longueur d'une chaîne.
* **`#include <time.h>`** : Fournit des fonctions pour manipuler le temps, comme `time` pour obtenir l'heure actuelle ou `clock` pour mesurer le temps écoulé.
* **`#include <stdlib.h>`** : Inclut des fonctions pour la gestion de mémoire dynamique (`malloc`, `free`), les conversions de chaînes en nombres (`atoi`, `atof`), et la génération de nombres aléatoires (`rand`, `srand`).
* **`#include <ctype.h>`** : Fournit des fonctions pour manipuler des caractères individuels, comme `isalpha` pour vérifier si un caractère est alphabétique, `isdigit` pour les chiffres, ainsi que `toupper` et `tolower` pour convertir des lettres en majuscules ou minuscules.
* **`#include <wchar.h>`** : Fournit des fonctions pour la manipulation de caractères larges (`wide characters`) et de chaînes larges, comme `wprintf` pour l'affichage de chaînes larges, `wcscpy` pour la copie, `wcscat` pour la concaténation, et `wcslen` pour la longueur des chaînes. Utilisé pour supporter l'Unicode et des jeux de caractères étendus.

## Références

### Gestion des Variables et des Expressions Lambda

- [Documentation C sur cppreference.com](https://en.cppreference.com/w/c) : Référence pour les fonctions standard et la gestion des chaînes de caractères en C.
- [GeeksforGeeks - Manipulation de chaînes et types en C](https://www.geeksforgeeks.org/c-programming-language/) : Explications sur les types et les chaînes en C, essentielle pour gérer les variables et leurs affectations.
- [TutorialsPoint - Les Piles et l'Évaluation des Expressions](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm) : Tutoriel sur les piles et le parsing d'expressions mathématiques.

### Utilisation des Structures et Tables de Symboles en C

- [OpenClassrooms - Structures et gestion des tables de symboles](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c) : Introduction à la gestion des tables de symboles pour stocker des variables, types et valeurs.
- [GeeksforGeeks - Implémentation des tables de symboles](https://www.geeksforgeeks.org/symbol-table/): Tutoriels et exemples pour la gestion des tables de symboles et des variables en C.

### Parsing et Évaluation des Expressions Lambda

- [Real Python - Parsing des Expressions Lambda](https://realpython.com/lexical-syntax-analysis/) : Bien que le contenu soit en Python, les concepts de parsing d'expressions lambda s'appliquent aussi en C pour structurer l’analyse syntaxique.
- [Programiz - Évaluation des Expressions Mathématiques](https://www.programiz.com/c-programming/examples/infix-evaluation) : Exemples sur l’évaluation des expressions en C, avec un accent sur le parsing et l’évaluation par des règles de priorité.

### Ressources Générales et Support Technique
* [ChatGPT par OpenAI](https://chat.openai.com/) : Outil de support interactif pour poser des questions, résoudre des problèmes de code, et approfondir vos connaissances en programmation C et Python.

## Difficulté

* **Gestion des types et des contraintes de variables (Exercice 5.1)** : La prise en charge de l'affectation de variables exige une gestion précise des types (entiers, réels, chaînes) avec des vérifications strictes pour empêcher tout changement de type une fois qu’une variable est définie. Le respect de cette contrainte de type rend la gestion de la table de symboles complexe, en particulier pour la validation des noms de variables UTF-8.

* **Parsing et évaluation des expressions lambda (Exercice 5.2)** : L'implémentation du support des expressions lambda implique un parsing avancé pour extraire et analyser des fonctions anonymes. L'intégration d'un mécanisme pour remplacer dynamiquement les variables dans les expressions mathématiques et évaluer le résultat introduit des défis en termes de performance et de robustesse, surtout avec les erreurs potentielles (par exemple, variables non définies).

* **Gestion des erreurs et robustesse** : Chaque étape du TP nécessite une gestion rigoureuse des erreurs, qu'il s'agisse d'erreurs de syntaxe dans les expressions lambda ou de variables non définies. La détection et la communication d'erreurs précises à l'utilisateur ajoutent une couche de complexité supplémentaire.

## Commentaires

* **Développement modulaire et structuré (Exercices 5.1 et 5.2)** : La création de modules pour la gestion des variables et des expressions lambda améliore la lisibilité et la réutilisabilité du code. La table de symboles et le parseur d'expressions lambda sont conçus comme des composants indépendants, ce qui facilite leur maintenance et les futures extensions de l'interpréteur.

* **Simplicité et efficacité dans la gestion des types** : Les algorithmes pour la vérification des types et la gestion des affectations sont conçus pour être simples et efficaces, minimisant les vérifications redondantes. La structure de la table de symboles permet une affectation rapide des valeurs et une récupération immédiate pour l'évaluation des expressions.

* **Intégration fluide des expressions lambda** : L'ajout des expressions lambda à l'interpréteur permet d’évaluer des expressions mathématiques avancées de manière intuitive. Cette fonctionnalité rend l'interpréteur plus interactif et proche de l’utilisation d’un langage fonctionnel simple, tout en conservant la simplicité de l’interface.

* **Optimisation et gestion de la mémoire** : La gestion des variables et des expressions dans une table de symboles requiert une attention particulière à l'optimisation de la mémoire et à la libération des ressources après utilisation, en particulier pour les expressions qui remplacent des variables dynamiquement.
