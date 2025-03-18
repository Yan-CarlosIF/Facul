#include <stdio.h>
#define linEcol 3

void multiplicaLinha(int (*m)[linEcol], int tam);
void mostra(int (*m)[linEcol], int tam);

int main()
{
    int A[linEcol][linEcol]; // Questão pede tam = 6

    for (int i = 0; i < linEcol; i++)
    {
        for (int j = 0; j < linEcol; j++)
        {
            printf("Digite [%dx%d]:", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMatriz antes da funcao:\n");
    mostra(A, linEcol);
    multiplicaLinha(A, linEcol);
    printf("\nMatriz depois da funcao:\n");
    mostra(A, linEcol);

    return 0;
}

void multiplicaLinha(int (*m)[linEcol], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int diagonal = m[i][i];
        for (int j = 0; j < linEcol; j++)
        {
            m[i][j] *= diagonal;
        }
    }
}

void mostra(int (*m)[linEcol], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < linEcol; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
