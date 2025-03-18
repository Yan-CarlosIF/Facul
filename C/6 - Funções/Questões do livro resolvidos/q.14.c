/* Crie uma sub-rotina que receba como parâmetro dois vetores de dez elementos inteiros positivos e
mostre o vetor união dos dois primeiros. */

#include <stdio.h>

void uniao(int *a, int *b, int *uni, int tam);

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, B[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 10}, uni[20];

    uniao(A, B, uni, 10);

    return 0;
}

void uniao(int *a, int *b, int *uni, int tam)
{
    int contUni = 0;

    for (int i = 0; i < tam; i++)
    {
        int possui = 0;
        for (int j = 0; j < contUni; j++)
        {
            if (a[i] == uni[j])
            {
                possui = 1;
                break;
            }
        }

        if (!possui)
        {
            uni[contUni++] = a[i];
        }
        possui = 0;

        for (int j = 0; j < contUni; j++)
        {
            if (b[i] == uni[j])
            {
                possui = 1;
                break;
            }
        }

        if (!possui)
        {
            uni[contUni++] = b[i];
        }    
    }

    for (int i = 0; i < contUni; i++)
    {
        printf("%d ", uni[i]);
    }
}