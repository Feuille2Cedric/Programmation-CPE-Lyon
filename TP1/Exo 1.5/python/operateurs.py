def calcul(a,b):
    addition = a+b
    soustraction = a-b
    multiplication = a*b
    division = a/b
    modulo = a%b
    egal = calcul_egal(a,b)
    sup = calcul_supperieur(a,b)

    print("addition", addition)
    print("soustraction", soustraction)
    print("multiplication", multiplication)
    print("division", division)
    print("modulo", modulo)
    print("egal", egal)
    print("sup", sup)

def calcul_egal(a,b):
    if a == b : 
        return True
    else:
        return False
    
def calcul_supperieur(a,b):
    if a > b : 
        return True
    else : 
        return False

def main():
    a = 16
    b = 3
    calcul(a,b)

if __name__ == "__main__":
    main()