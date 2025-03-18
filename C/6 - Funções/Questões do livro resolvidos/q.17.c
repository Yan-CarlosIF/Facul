#include <stdio.h>
  
int soma(int (*m)[5], int lin)
{
    int soma = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            soma += m[i][j];
        }
    }

    return soma;
}

int main()
{
    int m[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Digite [%dx%d]:", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    int somaResultado = soma(m, 5);

    printf("\nSoma dos elementos da matriz: %d", somaResultado);
    return 0;
}

/*  PASSANDO POR VALOR:
   
    int soma(int m[5][5])
    {
        int soma = 0;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                soma += m[i][j];
            }
        }

        return soma;
    }
*/