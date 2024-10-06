# Comparaison entre C et Python

Ce document compare les langages de programmation C et Python en se concentrant sur plusieurs aspects clés de la programmation.

## 1. Bases de la programmation

### Affichage des données
- **C** : Utilise la fonction `printf()` pour afficher des données. La syntaxe nécessite des spécificateurs de format pour différents types de données (comme `%d` pour un entier, `%f` pour un flottant).
- **Python** : Utilise la fonction `print()`, qui est plus simple et ne nécessite pas de spécificateurs de type. 

**Exemple en C :**
```c
#include <stdio.h>

int main() {
    printf("Hello, World! %dn", 42);
    return 0;
}
```

**Exemple en Python :**
```python
print("Hello, World!", 42)
```

### Gestion de la mémoire
- **C** : Nécessite une gestion explicite de la mémoire (allocation et libération) avec des fonctions comme `malloc()` et `free()`. 
- **Python** : Gère automatiquement la mémoire grâce à un garbage collector.

## 2. Manipulation des variables

### Déclaration des types
- **C** : Utilise un typage statique, ce qui signifie que le type de chaque variable doit être déclaré explicitement lors de sa création.
  
**Exemple en C :**
```c
int a = 5;
float b = 3.14;
```

- **Python** : Utilise un typage dynamique, ce qui signifie que le type de la variable est déterminé automatiquement à l'exécution. Python 3.5+ prend également en charge les annotations de type pour le typage statique, mais elles sont facultatives.

**Exemple en Python :**
```python
a = 5       # a est un entier
b = 3.14    # b est un flottant
```

Avec annotations de type :
```python
a: int = 5
b: float = 3.14
```

## 3. Opérateurs

### Opérateurs arithmétiques
Les opérateurs arithmétiques de base (+, -, *, /) sont similaires dans les deux langages. Cependant, Python a un opérateur de puissance (`**`), tandis qu'en C, la puissance nécessite une fonction de bibliothèque (`pow()`).

**Exemple en C :**
```c
#include <math.h>
int a = 2;
int b = 3;
int result = pow(a, b); // 2^3
```

**Exemple en Python :**
```python
a = 2
b = 3
result = a ** b  # 2^3
```

### Opérateurs logiques et bit à bit
- **Logiques** : `&&`, `||`, `!` en C vs `and`, `or`, `not` en Python.
- **Bit à bit** : `&`, `|`, `^`, `~`, `<<`, `>>` sont les mêmes dans les deux langages.

**Exemple de comparaison logique :**
```c
// C
if (a > 1 && b < 3) {
    // Code
}
```
```python
# Python
if a > 1 and b < 3:
    # Code
```

## 4. Boucles et structures de contrôle

### Délimitation des blocs de code
- **C** : Utilise des accolades `{ }` pour délimiter les blocs de code.
- **Python** : Utilise l'indentation pour délimiter les blocs de code, ce qui rend le code plus lisible.

**Exemple de boucle `for` :**
```c
// C
for (int i = 0; i < 5; i++) {
    printf("%dn", i);
}
```
```python
# Python
for i in range(5):
    print(i)
```

### Boucles (`for`, `while`) et conditions (`if`, `else`)
Les deux langages ont des boucles `for` et `while` et des structures conditionnelles `if`, `else`. Cependant, la syntaxe diffère.

**Boucle `while` :**
```c
// C
int i = 0;
while (i < 5) {
    printf("%dn", i);
    i++;
}
```
```python
# Python
i = 0
while i < 5:
    print(i)
    i += 1
```

## 5. Conversion et formatage

### Formatage de chaînes
- **C** : Utilise `printf()` pour le formatage avec des spécificateurs de type (comme `%d`, `%f`).
  
**Exemple en C :**
```c
printf("L'âge est %d ansn", 25);
```

- **Python** : Utilise les `f-strings` (à partir de Python 3.6) pour le formatage des chaînes, ce qui est plus simple et intuitif.

**Exemple en Python :**
```python
age = 25
print(f"L'âge est {age} ans")
```

### Conversion de types
- **C** : Les conversions doivent être effectuées explicitement.
  
**Exemple de conversion en entier :**
```c
float f = 3.14;
int i = (int)f;  // Conversion explicite
```

- **Python** : Dispose de fonctions intégrées comme `int()`, `float()`, `str()` pour la conversion de types.
  
**Exemple en Python :**
```python
f = 3.14
i = int(f)  # Conversion en entier
```

### Conversion en binaire
- **C** : La conversion en binaire n'est pas native ; cela nécessite du code supplémentaire.
  
**Exemple en C :**
```c
void toBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}
```

- **Python** : Utilise la fonction `bin()` pour convertir un nombre en binaire.
  
**Exemple en Python :**
```python
n = 42
print(bin(n))  # Affiche '0b101010'
```
