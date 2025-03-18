#include <stdio.h>

void trocaNegPor0(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < 0)
        {
            vet[i] = 0;
        }
    }
}

int main()
{
    const int tam = 5;
    int A[tam];

    printf("\nChama:\n");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &A[i]);
    }

    trocaNegPor0(A, tam);

    printf("\nVetor:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
