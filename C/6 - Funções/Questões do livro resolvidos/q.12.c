#include <stdio.h>

void numerosPerfeitos(int *vetR);

int main()
{
    int vetR[3];
    numerosPerfeitos(vetR);
    printf("\nNumeros perfeitos:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", vetR[i]);
    }
    return 0;
}

void numerosPerfeitos(int *vetR)
{
    int cont = 0;
    for (int i = 1; cont < 3; i++)
    {
        int soma = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                soma += j;
            }
        }

        if (soma == i)
        {
            vetR[cont++] = i;
        }
    }
}
