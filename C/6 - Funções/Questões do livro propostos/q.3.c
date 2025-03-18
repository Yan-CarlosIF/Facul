/* Elabore uma sub-rotina que receba dois números como parâmetros e retorne 0, se o primeiro número for
divisível pelo segundo número. Caso contrário, deverá retornar o próximo divisor.  */

#include <stdio.h>

int divisiveis(int *n1, int *n2)
{
    if (*n1 % *n2 == 0)
    {
        return 0;
    }
    else
    {
        if (*n1 > *n2) 
        {
            for (int i = *n2; i <= *n1; i++)
            {
                if (*n1 % i == 0)
                {
                    return i;
                }
            }
        }
        else 
        {
            for (int i = *n2; i >= 1; i--)
            {
                if (*n1 % i == 0)
                {
                    return i;
                }
            }
        }
    }
}

int main()
{
    int n1, n2;

    printf("Digite dois numeros:");
    scanf("%d %d", &n1, &n2);

    int resultado = divisiveis(&n1, &n2);

    if (resultado == 0)
    {
        printf("\n%d eh divisivel por %d", n1, n2);
    }
    else
    {
        printf("\nO proximo divisor de %d em relacao a %d eh: %d", n1, n2, resultado);
    }
    return 0;
}
