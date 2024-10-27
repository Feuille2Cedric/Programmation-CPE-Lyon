# Scripts de manipulation de chaînes de caractères en Python et C

Ce projet comprend différents scripts en Python et en C permettant de manipuler des chaînes de caractères de diverses manières : concaténation, copie, calcul de longueur, et autres opérations de base. Il inclut également un interpréteur de commandes interactif et un évaluateur d'expressions mathématiques.

## Bibliothèques utilisées

### C
* **`#include <stdio.h>`** : Fournit les fonctions d'entrée/sortie standard, telles que `printf` pour l'affichage, `scanf` pour la lecture de l'entrée, et des fonctions pour la manipulation de fichiers (`fopen`, `fclose`, etc.).
* **`#include <string.h>`** : Contient des fonctions pour manipuler des chaînes de caractères, comme `strcpy` pour la copie, `strcat` pour la concaténation, et `strlen` pour calculer la longueur d'une chaîne.
* **`#include <time.h>`** : Fournit des fonctions pour manipuler le temps, comme `time` pour obtenir l'heure actuelle ou `clock` pour mesurer le temps écoulé.
* **`#include <stdlib.h>`** : Inclut des fonctions pour la gestion de mémoire dynamique (`malloc`, `free`), les conversions de chaînes en nombres (`atoi`, `atof`), et la génération de nombres aléatoires (`rand`, `srand`).
* **`#include <ctype.h>`** : Fournit des fonctions pour manipuler des caractères individuels, comme `isalpha` pour vérifier si un caractère est alphabétique, `isdigit` pour les chiffres, ainsi que `toupper` et `tolower` pour convertir des lettres en majuscules ou minuscules.

## Références

### C
- [Documentation C sur cppreference.com](https://en.cppreference.com/w/c) : Référence complète pour les fonctions de manipulation de chaînes (`strcpy`, `strlen`, `strcmp`).
- [GeeksforGeeks - Manipulation de chaînes en C](https://www.geeksforgeeks.org/c-programming-language/) : Introduction à la manipulation de chaînes en C, couvrant la concaténation, la copie, et la gestion de mémoire.
- [GeeksforGeeks - Structures et Pointeurs en C](https://www.geeksforgeeks.org/structures-c/) : Concepts essentiels pour manipuler des structures en C, utiles pour ajouter des commandes dans l'interpréteur.
- [Programiz - Structs en C](https://www.programiz.com/c-programming/c-structures) : Introduction aux structures en C pour stocker des commandes et des fonctions.
- [OpenClassrooms - Les structures de données en C](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/18109-les-structures-de-donnees) : Approfondissement des structures et de leur manipulation.
- [Documentation C sur les fonctions](https://en.cppreference.com/w/c/language/function) : Concepts sur les pointeurs de fonction, utiles pour assigner des commandes à des fonctions dans des structures.
- [Documentation C sur `<ctype.h>`](https://en.cppreference.com/w/c/string/byte) : Guide sur les fonctions de manipulation des caractères (`toupper`, `tolower`, `isalpha`), utiles pour gérer la casse et les caractères spéciaux.
- [GeeksforGeeks - Manipulation de chaînes et des caractères](https://www.geeksforgeeks.org/c-programming-language/) : Introduction et exemples de manipulation des chaînes pour adapter les commandes en français.
- [OpenClassrooms - Gestion des chaînes en C](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c) : Explication de la gestion des caractères, des chaînes de caractères et des comparaisons.
- [TutorialsPoint - Lexique et Syntaxe en C](https://www.tutorialspoint.com/c_standard_library/c_macro_syntax.htm) : Concepts de base sur la syntaxe C pour créer des structures de tokenization et parsing.
- [GeeksforGeeks - Tokenizer en C](https://www.geeksforgeeks.org/tokenizing-a-string-in-c/) : Techniques pour créer un tokenizeur avec des chaînes en C.
- [Programiz - Créer un Parseur en C](https://www.programiz.com/c-programming/examples/infix-evaluation) : Exemples et explications sur l’analyse syntaxique et l’évaluation des expressions.

### Ressources Générales et Support Technique
* [ChatGPT par OpenAI](https://chat.openai.com/) : Outil de support interactif pour poser des questions, résoudre des problèmes de code, et approfondir vos connaissances en programmation C et Python.

## Difficulté

* **Exploration et compréhension de l'interpréteur de commandes (Exercice 3.1)** : La prise en main de l’interpréteur de commandes en C exige de bien comprendre la manipulation de chaînes de caractères, y compris la lecture des entrées utilisateur, la gestion des commandes non reconnues, et l'affichage de messages en fonction des commandes saisies.

* **Ajout de fonctionnalités avec des structures et tableaux de fonctions (Exercice 3.2)** : Pour ajouter des fonctionnalités comme `help`, `version` ou `echo`, il est nécessaire de maîtriser l'utilisation des structures (`struct`) et des pointeurs de fonctions pour gérer dynamiquement les commandes. Cet exercice demande aussi une bonne compréhension des tableaux de structures pour associer des commandes et leurs fonctions.

* **Support multilingue et gestion des caractères spéciaux (Exercice 3.3)** : L’ajout du support des commandes en français introduit des difficultés liées aux différences de casse et à la gestion des accents. Manipuler les chaînes de manière insensible à la casse et aux accents demande une bonne maîtrise des fonctions de `ctype.h` pour le traitement des caractères individuels.

* **Création d’un tokenizeur, parseur, et évaluateur d’expressions mathématiques (Exercice 3.4)** : La création d’un analyseur lexical (tokenizer) et syntaxique (parseur) en C pour les expressions mathématiques est l’un des exercices les plus avancés. Il nécessite des compétences en traitement de chaînes, en gestion des erreurs de syntaxe et en manipulation des structures de données pour représenter les expressions. La conception d’un évaluateur capable de traiter des opérations comme `+`, `-`, `*`, `/` et de gérer des erreurs (par exemple, la division par zéro) est également un défi important.

## Commentaires

* **Simplicité et lisibilité des scripts (Exercice 3.1)** : Les premiers exercices sont conçus pour être simples et lisibles, en introduisant progressivement les bases de la manipulation des chaînes de caractères en C. Cette simplicité aide à comprendre comment un interpréteur de commandes peut réagir à différentes entrées utilisateur et affiche des messages clairs. La structure simple de l'interpréteur rend chaque commande facile à suivre et à modifier, ce qui est essentiel pour ceux qui découvrent le C ou la gestion de chaînes.

* **Organisation modulaire et extensibilité (Exercice 3.2)** : En ajoutant de nouvelles fonctionnalités, comme les commandes `help` et `version`, le projet adopte une organisation plus modulaire. Chaque commande devient une fonction spécifique, ce qui améliore la lisibilité et facilite l’ajout de nouvelles commandes sans complexifier le code principal. La création d’un tableau de structures pour stocker les commandes et les fonctions associées permet d'améliorer la gestion des commandes et rend le code plus extensible et facile à maintenir.

* **Support multilingue et gestion des erreurs (Exercice 3.3)** : L’introduction de commandes en français enrichit l’interpréteur et le rend plus accessible, tout en ajoutant des défis de gestion de casse et de caractères spéciaux. Le projet pourrait être optimisé pour traiter les commandes indépendamment de la langue ou des erreurs d'orthographe, en fournissant une interface multilingue intuitive. La gestion des erreurs devient également plus complexe et importante, en aidant l'utilisateur avec des messages d'erreur clairs lorsqu'une commande est incorrecte.

* **Robustesse et optimisation de l'évaluation des expressions mathématiques (Exercice 3.4)** : La création du tokenizeur, parseur, et évaluateur nécessite une organisation rigoureuse et des optimisations pour garantir des performances stables. Ce niveau de complexité demande des structures bien pensées pour traiter efficacement les opérations mathématiques et gérer des erreurs comme la division par zéro. Des optimisations supplémentaires, comme l'utilisation de fonctions mathématiques intégrées et une gestion efficace des tokens, pourraient améliorer la robustesse et la performance de l'évaluateur, notamment pour des expressions plus complexes.
