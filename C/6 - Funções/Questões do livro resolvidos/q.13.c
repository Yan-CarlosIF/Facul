#include <stdio.h>
#include <stdlib.h>

void fatorialArray(int *arrayA, int *arrayB, int tam);
int fatorial(int num);

int main()
{
    int arrayA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, arrayB[10];

    fatorialArray(arrayA, arrayB, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arrayB[i]);
    }

    return 0;
}

void fatorialArray(int *arrayA, int *arrayB, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        arrayB[i] = fatorial(arrayA[i]);
    }
}

int fatorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * fatorial(num - 1);
    }
}
