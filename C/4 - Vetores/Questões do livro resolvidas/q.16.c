#include <stdio.h>
#define tam 10
#define tam2 5

int main()
{
    int vetor1[tam], vetor2[tam2], vetorR1[tam], vetorR2[tam];

    printf("Digite %d numeros:\n",tam);
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    printf("\nDigite mais %d numeros:\n",tam2);
    for (int i = 0; i < tam2; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    int contPar = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor1[i] % 2 == 0)
        {
            vetorR1[contPar] = vetor1[i];
            for (int j = 0; j < tam2; j++)
            {
                vetorR1[contPar] += vetor2[j];
            }
            contPar++;
        }
    }

    printf("\nVetor Resultante 1:\n");
    for (int i = 0; i < contPar; i++)
    {
        printf("%d ", vetorR1[i]);
    }

    int contImpar = 0;
    for (int i = 0; i < tam; i++)
    {
        int cont = 0;
        if (vetor1[i] % 2 != 0)
        {
            for (int j = 0; j < tam2; j++)
            {
                if (vetor1[i] % vetor2[j] == 0)
                {
                    cont++;
                }
            }
            vetorR2[contImpar++] = cont;
        }
    }

    printf("\nVetor Resultante 2:\n");
    for (int i = 0; i < contImpar; i++)
    {
        printf("%d ", vetorR2[i]);
    }

    return 0;
}
