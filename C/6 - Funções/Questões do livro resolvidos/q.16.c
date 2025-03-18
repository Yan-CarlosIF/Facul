/*  Crie uma sub-rotina que receba dois vetores A e B de dez elementos inteiros como parâmetro. A sub-
-rotina deverá determinar e mostrar um vetor C que contenha os elementos de A e B em ordem decrescente. 
O vetor C deverá ser mostrado no programa principal. */
#include <stdio.h>

void ordenaDecrescente(int *a, int *b, int *c, int tam)
{   
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        c[j++] = a[i];
        c[j++] = b[i];
    }

    for (int i = 0; i < tam * 2; i++)
    {
        for (int j = i; j < tam * 2; j++)
        {
            if (c[i] < c[j])
            {
                int aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, c[20];

    ordenaDecrescente(a, b, c, 10);

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}