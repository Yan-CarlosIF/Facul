#include <stdio.h>
#define linEcol 5

float mediaAbaixoDiagonal(int (*m)[linEcol], int tam);

int main()
{
    int A[linEcol][linEcol] = { // Questão pede tam = 12 (Loucura)
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    float media = mediaAbaixoDiagonal(A, linEcol);
    printf("Media aritmetica dos elementos abaixo da diagonal principal: %.1f", media);
    return 0;
}

float mediaAbaixoDiagonal(int (*m)[linEcol], int tam)
{
    int media = 0, limite = 0, cont = 0;
    for (int i = 1; i < tam; i++)
    {
        for (int j = 0; j <= limite && limite < linEcol - 1; j++)
        {
            media += m[i][j];
            cont++;
        }
        limite++;
    }

    return media/(float)cont;
}
