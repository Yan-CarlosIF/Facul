#include <stdio.h>

int main()
{
    int i,j,k,a[4][5],b[5][2],c[4][2],soma=0;
    printf("Primeira matriz:\n");
    for (i=0;i<4;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("Digite o numero da %d coluna da %d linha:",j+1,i+1);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("Segunda matriz:\n");
    for (i=0;i<5;i++)
    {
        for (j=0;j<2;j++)
        {
            printf("Digite o numero da %d coluna da %d linha:",j+1,i+1);
            scanf("%d",&b[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<4;i++)
    {
        for (k=0;k<2;k++)
        {
            for (j=0;j<5;j++)
            {
                soma+=a[i][j]*b[j][k];
            }
            c[i][k]=soma;
            soma = 0;
        }
    }
    printf("Produto matricial:\n\n");
    for (i=0;i<4;i++)
    {
        printf("linha %d:\n",i+1);
        for (j=0;j<2;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;   
}