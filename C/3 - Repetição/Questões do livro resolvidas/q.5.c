#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * fatorial(num - 1);
    }
}

int main()
{
    int n, denominador;
    float x, s;

    do
    {
        printf("Digite um valor positivo para X:");
        scanf("%f", &x);
    } while (x <= 0);
    printf("Digite um numero de termos a serem calculados:");
    scanf("%d", &n);
    denominador = 1;
    s = 0;
    int rapadura = 0;

    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        float termo = (pow(x, i + 1) / fatorial(denominador));
        if (i % 2 != 0)
        {
            termo = -termo;
        }
        
        printf("Termo %d: %.2f, denominador = %d, expoente = %d, conta = %.0f^%d/%d\n", i, termo, denominador, i + 1, x, i + 1, fatorial(denominador));

        if (!rapadura)
        {
            denominador++;
        }
        else 
        {
            denominador--;
        }

        if (denominador >= 4)
        {
            rapadura = 1;
        }
        if (denominador <= 1)
        {
            rapadura = 0;
        }
        s += termo;
    }

    printf("\nS = %f\n", s);
    return 0;
}