#include <stdio.h>

int main()
{
    int i,vetor1[5],vetor2[5],vetor3[10];
    printf("Digite 5 numeros do vetor 1:\n");
    for (i=0;i<5;i++)
    {
        scanf("%d",&vetor1[i]);
    }
    printf("Numeros do vetor 1 em ordem crescente:\n");
    for (i=0;i<5;i++)
    {
        for (int j=i;j<5;j++)
        {
            if (vetor1[i]>vetor1[j])
            {
                int aux = vetor1[i];
                vetor1[i] = vetor1[j];
                vetor1[j] = aux;
            }
        }
        printf("%d\n",vetor1[i]);
    }
    printf("Digite 5 numeros do vetor 2:\n");
    for (i=0;i<5;i++)
    {
        scanf("%d",&vetor2[i]);
    }
    printf("Numeros do vetor 2 em ordem crescente:\n");
    for (i=0;i<5;i++)
    {
        for (int j=i;j<5;j++)
        {
            if (vetor2[i]>vetor2[j])
            {
                int aux = vetor2[i];
                vetor2[i] = vetor2[j];
                vetor2[j] = aux;
            }
        }
        printf("%d\n",vetor2[i]);
    }
    for (i = 0; i < 5; i++)
    {
        vetor3[i] = vetor1[i];
        vetor3[i+5] = vetor2[i];
    }
    printf("Numeros do vetor 1 e 2 em ordem crescente:\n");
    for (i=0;i<10;i++)
    {
        for (int j=i;j<10;j++)
        {
            if (vetor3[i]>vetor3[j])
            {
                int aux = vetor3[i];
                vetor3[i] = vetor3[j];
                vetor3[j] = aux;
            }
        }
        printf("%d\n",vetor3[i]);
    }
    return 0;
}