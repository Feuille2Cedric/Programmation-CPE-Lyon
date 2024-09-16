import sys

# Déclaration de différentes variables pour examiner leur taille
int_value = 42
float_value = 42.0
bool_value = True
str_value = "Hello, World!"
list_value = [1, 2, 3, 4, 5]
tuple_value = (1, 2, 3, 4, 5)
dict_value = {"key1": "value1", "key2": "value2"}

# Affichage des tailles en mémoire des différents types de données
print(f"Taille d'un entier (int) : {sys.getsizeof(int_value)} octets")
print(f"Taille d'un flottant (float) : {sys.getsizeof(float_value)} octets")
print(f"Taille d'un booléen (bool) : {sys.getsizeof(bool_value)} octets")
print(f"Taille d'une chaîne de caractères (str) : {sys.getsizeof(str_value)} octets")
print(f"Taille d'une liste (list) : {sys.getsizeof(list_value)} octets")
print(f"Taille d'un tuple (tuple) : {sys.getsizeof(tuple_value)} octets")
print(f"Taille d'un dictionnaire (dict) : {sys.getsizeof(dict_value)} octets")