#include <stdio.h>

int somaEntre(int n1, int n2)
{
    if (n1 < 0)
    {
        n1 *= -1;
    }

    if (n2 < 0)
    {
        n2 *= -1;
    }

    int soma = 0;
    if (n1 > n2)
    {
        for (int i = n2 + 1; i < n1; i++)
        {
            soma += i;
        }
    }
    else
    {
        for (int i = n1 + 1; i < n2; i++)
        {
            soma += i;
        }
    }

    return soma;
}

int main()
{
    int numero1, numero2;

    printf("Digite 2 numeros:");
    scanf("%d %d", &numero1, &numero2);

    int resultadoSoma = somaEntre(numero1, numero2);

    printf("\nResultado da soma: %d\n", resultadoSoma);
    return 0;
}