#include <stdio.h>

int somaDeInteiros(int a, int b, int c)
{
    int soma = 0;
    if (b > c)
    {
        for (int i = c; i <= b; i++)
        {
            if (i % a == 0)
            {
                soma += i;
            }
        }
    }
    else 
    {
        for (int i = b; i <= c; i++)
        {
            if (i % a == 0)
            {
                soma += i;
            }
        }
    }

    return soma;
}

int main()
{
    int a, b, c;
    do { 
    printf("Digite o valor de A:");
    scanf("%d", &a);
    } while (a <= 1);
    
    printf("Digite o valor de B:");
    scanf("%d", &b);
    printf("Digite o valor de C:");
    scanf("%d", &c);

    int resultadoSoma = somaDeInteiros(a, b, c);

    printf("\nSoma dos numeros: %d\n", resultadoSoma);
    return 0;
}