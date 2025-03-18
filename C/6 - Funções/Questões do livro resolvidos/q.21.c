#include <stdio.h>
#include <stdbool.h>

bool ePrimo(int *num);
int somaPrimos(int *x, int *y);

int main()
{
    int x, y;

    do {
        printf("Digite numero de x e y:\n");
        scanf("%d %d", &x, &y);
        if (x < y)
        {
            printf("\nA soma dos primos entre %d e %d = %d\n", x, y, somaPrimos(&x, &y));
        }
        else
        {
            printf("\nO numero de x deve ser menor que o de y!\n");
        }
        printf("\n");
    } while (x != y);

    return 0;
}

bool ePrimo(int *num)
{
    if (num < 2) return false;

    int cont = 0;
    for (int i = 1; i <= *num; i++)
    {
        if (*num % i == 0)
        {
            cont++;
        }
    }

    if (cont == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int somaPrimos(int *x, int *y)
{
    int soma = 0;

    for (int i = *x; i <= *y; i++)
    {
        if (ePrimo(&i))
        {
            soma += i;
        }
    }
    return soma;
}