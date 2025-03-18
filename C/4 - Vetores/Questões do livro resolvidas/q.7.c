#include <stdio.h>

int main()
{
    int i,vetor[8];
    printf("Digite 8 numeros:\n");
    for (i=0;i<8;i++)
    {
        scanf("%d",&vetor[i]);
    }
    for (i=0;i<8;i++)
    {
        for (int j=i;j<8;j++)
        {
            if (vetor[i]>vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("\nOs numeros digitados em ordem crescente:\n");
    for (i=0;i<8;i++)
    {
        printf("%d\n",vetor[i]);
    }
    return 0;
}