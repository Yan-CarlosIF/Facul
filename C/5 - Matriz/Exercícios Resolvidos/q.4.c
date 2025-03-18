#include <stdio.h>
#define lin 10
#define col 20
int main()
{
    int i,j,matriz[lin][col],vet_soma[lin],matriz_r[lin][col];
    for (i = 0; i < lin; i++)
    {
        vet_soma[i]=0;
        for (j=0;j<col;j++)
        {
            printf("Digite o %d numero da %d linha:",j+1,i+1);
            scanf("%d",&matriz[i][j]);
            vet_soma[i]+=matriz[i][j];
        }
        printf("\n");
    }   
    for (i = 0; i < lin; i++)
    {
        for (j=0;j<col;j++)
        {
            matriz_r[i][j]=vet_soma[i]*matriz[i][j];
        }
    }
    printf("\n");
    for (i = 0; i < lin; i++)
    {
        printf("Linha %d:\n",i+1);
        for (j=0;j<col;j++)
        {
            printf("Coluna resultante %d = %d\n",j+1,matriz_r[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}