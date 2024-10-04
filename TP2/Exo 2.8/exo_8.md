# Rapport Comparatif : Programmation en C et Python

## 1. Débogage

### C (avec gdb)
- **Outil :** gdb (GNU Debugger)
- **Techniques :**
  - Point d'arrêt : permet de stopper l'exécution à une ligne spécifique.
  - Inspection de variables : permet de voir et modifier les valeurs des variables à différents points d'exécution.
  - Exécution pas à pas : permet de suivre l'exécution du programme ligne par ligne.
- **Différences :**
  - Le débogage en C nécessite une compilation avec des symboles de débogage (option `-g` avec gcc).
  - gdb est plus complexe à utiliser, mais offre un contrôle fin sur l'exécution du programme.

### Python (avec pdb)
- **Outil :** pdb (Python Debugger)
- **Techniques :**
  - Point d'arrêt : utilisation de `pdb.set_trace()` pour stopper l'exécution.
  - Inspection de variables : les variables peuvent être inspectées directement dans le shell pdb.
  - Exécution pas à pas : commande `n` (next) pour exécuter la ligne suivante.
- **Différences :**
  - pdb est intégré à Python et plus simple à utiliser pour les développeurs débutants.
  - Python offre une approche plus dynamique avec des modifications en temps réel des valeurs de variables.

## 2. Chaîne de Compilation

### C avec gcc
- **Étapes :**
  1. **Prétraitement :** traitement des directives de préprocesseur (ex. `#include`, `#define`).
  2. **Compilation :** conversion du code source en code objet, vérification de la syntaxe et des types.
  3. **Assemblage :** conversion du code objet en langage machine.
  4. **Édition des liens :** rassemblement de plusieurs fichiers objets en un exécutable final.
- **Gestion des modules :** Les modules doivent être compilés séparément et reliés ensemble, ce qui nécessite une gestion plus stricte des dépendances.

### Python
- **Gestion des modules :** Python utilise un système d'importation qui permet de charger des modules à la volée, sans compilation préalable.
- **Dynamique :** La gestion des modules en Python est plus flexible, permettant l'importation conditionnelle et dynamique.

## 3. Inspection de Code

### Python (avec dis)
- **Outil :** dis (module pour désassembler le bytecode Python)
- **Utilisation :** permet d'examiner le bytecode généré par l'interpréteur Python pour chaque fonction.
- **Avantage :** Offre une compréhension approfondie de la manière dont Python exécute le code.

### C
- **Outils disponibles :** pas d'équivalent direct à dis ; cependant, on peut utiliser des outils comme `objdump` ou `gdb` pour inspecter le code compilé.
- **Limitation :** Cela nécessite une bonne compréhension des architectures et des langages de bas niveau.

## 4. Manipulation de Chaînes de Caractères

### C
- **Techniques :**
  - Utilisation de la bibliothèque standard (`<string.h>`).
  - Fonctions comme `strcpy()`, `strcat()`, `strlen()`, etc.
- **Avantages :** Contrôle fin sur la mémoire et les performances.
- **Inconvénients :** Gestion manuelle de la mémoire, risque de débordements de tampon, plus complexe à utiliser.

### Python
- **Techniques :**
  - Méthodes de chaîne intégrées (ex. `str.upper()`, `str.lower()`, `str.replace()`).
  - Utilisation de f-strings pour une interpolation de chaîne facile (ex. `f"Bonjour {nom}"`).
- **Avantages :** Simple et intuitif, gestion automatique de la mémoire.
- **Inconvénients :** Moins performant pour des opérations massives sur des chaînes par rapport à C.

## 5. Gestion des Données et Recherche dans les Fichiers

### C (Structures)
- **Structures :** Utilisation de `struct` pour définir des types de données complexes.
- **Techniques de recherche :** Utilisation de boucles et de fonctions de manipulation de chaînes pour rechercher des phrases dans des fichiers.

### Python (Classes)
- **Classes :** Utilisation de classes pour représenter des structures de données complexes (ex. `Etudiant`).
- **Dictionnaires :** Utilisation de dictionnaires pour stocker des données d’étudiants et faciliter les recherches.
- **Techniques de recherche :** Utilisation de méthodes de chaîne et de compréhension de liste pour rechercher facilement des phrases dans des fichiers.

## Tableau Comparatif

| Aspect                      | C                                      | Python                                 |
|-----------------------------|----------------------------------------|----------------------------------------|
| Débogage                    | gdb, plus complexe                     | pdb, plus simple                       |
| Chaîne de Compilation       | Prétraitement, compilation, assemblage | Gestion dynamique des modules          |
| Inspection de Code          | objdump, gdb                          | dis (bytecode)                        |
| Manipulation de Chaînes     | Fonctions standard, gestion manuelle   | Méthodes intégrées, f-strings         |
| Gestion des Données         | Structures                             | Classes et dictionnaires               |



## Conclusion
Les approches de programmation en C et en Python offrent des avantages et des inconvénients distincts. C fournit un contrôle fin sur les ressources système, mais nécessite une gestion plus rigoureuse de la mémoire et des types. Python, en revanche, privilégie la simplicité et la rapidité de développement, ce qui le rend plus accessible aux développeurs débutants.
