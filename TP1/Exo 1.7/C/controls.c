#include <stdio.h>

void calcul4()
{
    for (int i = 1; i <= 1000; i++) 
    {
        if (i % 4 == 0 && i % 6 != 0)
            printf("\n%d est divisible par 4 mais pas par 6", i);
    }
}

void calcul_5_7()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 5 == 0 && i % 10 != 0)
            printf("\n%d est divisible par 5 mais pas par 10", i);
        else if (i % 7 == 0 && i % 10 != 0)
            printf("\n%d est divisible par 7 mais pas par 10", i);
    }
    printf("\n");
}

void calcul_pair_8()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 8 == 0)
        {
            printf("\n%d est divisible par 8", i);
        }
    }
}

int main()
{
    calcul4();
    calcul_5_7(); 
    calcul_pair_8();

    return 0;
}