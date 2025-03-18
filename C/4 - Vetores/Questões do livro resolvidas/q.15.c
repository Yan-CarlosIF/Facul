#include <stdio.h>
#define tam 10
#define tam2 5
int main()
{
    int i,vetor1[tam],vetor2[tam2];
    printf("Digite %d numeros:\n",tam);
    for (i=0;i<tam;i++)
    {
        scanf("%d",&vetor1[i]);
    }
    printf("\nDigite mais %d numeros:\n",tam2);
    for (i=0;i<tam2;i++)
    {
        scanf("%d",&vetor2[i]);
    }
    for (i=0;i<tam;i++)
    {
        int vali = 0;
        printf("Numero %d\n",vetor1[i]);
        for (int j=0;j<tam2;j++)
        {
            if (vetor1[i]%vetor2[j]==0)
            {
                printf("Divisivel por %d na posicao %d\n",vetor2[j],j+1);
            }
            else
            {
                vali+=1;
            }
        }
        if (vali==tam2)
        {
            printf("Nenhum numero do 2 vetor eh divisivel por %d!\n",vetor1[i]);
        }
    }
}