import sys  # Importation du module sys pour accéder à getsizeof, qui retourne la taille d'un objet en mémoire

# Déclaration de différentes variables pour examiner leur taille
int_value = 42  # Entier
float_value = 42.0  # Nombre flottant
bool_value = True  # Booléen (valeur vraie ou fausse)
str_value = "Hello, World!"  # Chaîne de caractères
list_value = [1, 2, 3, 4, 5]  # Liste de cinq entiers
tuple_value = (1, 2, 3, 4, 5)  # Tuple de cinq entiers
dict_value = {"key1": "value1", "key2": "value2"}  # Dictionnaire avec deux paires clé-valeur

# Affichage des tailles en mémoire des différents types de données
# Utilisation de sys.getsizeof() pour obtenir la taille en octets de chaque variable
print(f"Taille d'un entier (int) : {sys.getsizeof(int_value)} octets")
print(f"Taille d'un flottant (float) : {sys.getsizeof(float_value)} octets")
print(f"Taille d'un booléen (bool) : {sys.getsizeof(bool_value)} octets")
print(f"Taille d'une chaîne de caractères (str) : {sys.getsizeof(str_value)} octets")
print(f"Taille d'une liste (list) : {sys.getsizeof(list_value)} octets")
print(f"Taille d'un tuple (tuple) : {sys.getsizeof(tuple_value)} octets")
print(f"Taille d'un dictionnaire (dict) : {sys.getsizeof(dict_value)} octets")
