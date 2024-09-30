def calcul4():
    for i in range(1, 1001, 1):
        if i % 4 == 0 and i % 6 != 0:
            print(i,"est divisible par 4 mais pas par 6")

def calcul_5_7():
    for i in range(1, 1001, 1):
        # if (i % 5 == 0 or i % 7 == 0) and i % 10 != 0:
        #     print(i, "est divisible par 5 ou par 7 mais pas par 10")

        # Deux manières de faire

        if i % 5 == 0 and i % 10 != 0:
            print(i,"est divisible par 5 mais pas par 10")
        elif i % 7 == 0 and i % 10 != 0:
            print(i,"est divisible par 7 mais pas par 10")

def calcul_pair_8():
    for i in range(1, 1001, 1):
        if i % 8 == 0: 
            print(i,"est divisible par 8")

def main():
    calcul4()
    calcul_5_7()
    calcul_pair_8()

if __name__ == "__main__":
    main()