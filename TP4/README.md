# Scripts de Manipulation de Chaînes de Caractères et d'Évaluation d'Expressions Arithmétiques en C

Ce projet comprend différents scripts en Python et en C permettant de manipuler des chaînes de caractères de diverses manières : concaténation, copie, calcul de longueur, et autres opérations de base. Il inclut également un interpréteur en langage C, avec un module avancé pour l'évaluation d'expressions arithmétiques en notations infixée et postfixée. Ce projet se concentre sur le développement de structures de données et d'algorithmes permettant d'analyser, de convertir et d'évaluer des expressions arithmétiques, en intégrant ces fonctionnalités de manière fluide dans un interpréteur de commandes existant.

## Bibliothèques utilisées

### C
* **`#include <stdio.h>`** : Fournit les fonctions d'entrée/sortie standard telles que `printf` et `scanf`.
* **`#include <math.h>`** : Fournit des fonctions mathématiques telles que `sqrt()`, `sin()`, `cos()`, et des constantes comme `M_PI` pour des calculs avancés.
* **`#include <stdlib.h>`** : Utilisé pour la gestion dynamique de la mémoire, les fonctions de conversion, et la génération de nombres aléatoires (`rand()`).
* **`#include <string.h>`** : Contient des fonctions pour manipuler les chaînes de caractères, comme `strcpy()`, `strstr()`, etc.

## Références

### Concepts de Parsing et d'Évaluation des Expressions

- [Documentation C sur cppreference.com](https://en.cppreference.com/w/c) : Référence pour les fonctions standards et la gestion des chaînes de caractères en C.
- [GeeksforGeeks - Conversion de Notations Infixée et Postfixée](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/) : Explication détaillée sur la conversion d'expressions en notation infixée vers leur forme postfixée, y compris l’utilisation de piles.
- [TutorialsPoint - Évaluation d'Expressions Postfixées](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm) : Tutoriel sur l'évaluation des expressions en notation postfixée avec une pile.
- [Programiz - Utilisation des Piles en C](https://www.programiz.com/dsa/stack) : Introduction aux structures de piles, avec des exemples en C, qui est essentielle pour gérer les opérandes et opérateurs.

### Utilisation des Piles en C

- [OpenClassrooms - Les Structures et les Piles en C](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c) : Introduction aux structures de données en C et à la création de piles.
- [GeeksforGeeks - Implémentation de Piles en C](https://www.geeksforgeeks.org/stack-data-structure/) : Implémentation et utilisation de la structure de pile, une ressource clé pour manipuler les expressions arithmétiques.

### Intégration dans un Interpréteur

- [OpenClassrooms - Créer un Interpréteur en C](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c) : Concepts d’interpréteurs et de gestion de commandes en C, avec des exemples de structuration de code.
- [Real Python - Notions de Parsing et d’Évaluation](https://realpython.com/lexical-syntax-analysis/) : Bien qu’en Python, cette ressource introduit les concepts de base du parsing et de l’évaluation, applicables également en C pour l’organisation du code.

### Ressources Générales et Support Technique
* [ChatGPT par OpenAI](https://chat.openai.com/) : Outil de support interactif pour poser des questions, résoudre des problèmes de code, et approfondir vos connaissances en programmation C et Python.

## Difficulté

* **Parsing et conversion des expressions (Exercices 4.1 et 4.2)** : La conversion d'une expression en notation infixée vers sa forme postfixée nécessite une compréhension approfondie de la gestion des priorités des opérateurs et de l'utilisation des piles. Il est essentiel de bien comprendre comment stocker les opérateurs et les opérandes pour gérer correctement l'ordre des opérations, notamment en intégrant les parenthèses pour modifier la priorité naturelle.

* **Manipulation de structures de pile pour évaluation (Exercice 4.3)** : L'évaluation des expressions postfixées demande de manipuler des piles d'opérandes, ce qui est plus complexe lorsque des erreurs d'évaluation (par exemple, division par zéro) doivent être correctement gérées. Ce processus exige également une gestion de la mémoire efficace, car chaque opération de pile doit manipuler les valeurs sans compromettre la stabilité du programme.

* **Intégration dans l'interpréteur existant (Exercice 4.4)** : L'intégration de l'évaluateur dans l'interpréteur de commandes existant est un défi d'architecture, car il nécessite de combiner harmonieusement les nouveaux modules avec ceux de l'interpréteur. Cela implique d'adapter l'interpréteur pour reconnaître et interpréter correctement les commandes incluant des expressions mathématiques, en invoquant le parser et l'évaluateur appropriés.

## Commentaires

* **Développement modulaire et réutilisable (Exercices 4.1 à 4.4)** : La conception des fonctions de parsing et d’évaluation en modules séparés facilite la lisibilité et la maintenance du code. Chaque fonction est autonome et peut être réutilisée ou modifiée indépendamment, ce qui est essentiel pour des projets de cette ampleur.

* **Simplicité des algorithmes de parsing et d'évaluation (Exercices 4.1 et 4.2)** : Les algorithmes de conversion et d'évaluation sont conçus pour être le plus simple possible tout en respectant les règles de priorité des opérations. En utilisant des structures de pile, on peut traiter efficacement les opérateurs et opérandes dans l’ordre souhaité.

* **Optimisation et gestion des erreurs (Exercice 4.3)** : L'évaluateur d'expressions postfixées est conçu pour être robuste et rapide, avec des vérifications d'erreurs telles que la gestion de la division par zéro. Des optimisations futures pourraient inclure la gestion de cas d'erreurs supplémentaires et l'amélioration de la gestion de la mémoire dans les opérations de pile.

* **Intégration fluide avec l'interpréteur (Exercice 4.4)** : L’ajout de cette fonctionnalité à l’interpréteur de commandes doit se faire de manière transparente pour l’utilisateur, permettant une manipulation intuitive des expressions mathématiques. L'interpréteur doit être capable de détecter et d'évaluer correctement une expression mathématique dès qu'elle est saisie.
