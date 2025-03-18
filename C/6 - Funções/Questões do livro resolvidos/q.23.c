#include <stdio.h>

void copiaMatriz(float (*m)[4], float *vet, int tam);

int main()
{
    const int lin = 3;
    const int col = 4;
    float m[lin][col], vet[lin * col];

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%dx%d]:", i , j);
            scanf("%f", &m[i][j]);
        }
    }

    copiaMatriz(m, vet, lin);

    printf("\nMatriz:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.1f ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor:\n");
    for (int i = 0; i < lin * col; i++)
    {
        printf("%.1f ", vet[i]);
    }

    return 0;
}

void copiaMatriz(float (*m)[4], float *vet, int tam)
{
    int k = 0;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vet[k++] = m[i][j];
        }
    }
}