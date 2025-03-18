#include <stdio.h>
#define linEcol 3

int menorElemento(int (*m)[linEcol], int tam)
{
    int menor = m[0][linEcol - 1];
    int j = linEcol - 1;
    for (int i = 0; i < tam; i++)
    {
        if (m[i][j] < menor)
        {
            menor = m[i][j];
        }
        j--;
    }

    return menor;
}

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

    printf("\nMenor elemento da diagonal secundária da matriz: %d", menorElemento(A, linEcol));

    return 0;
}
