#include <stdio.h>

int main()
{
    int i,j,menor_l,coluna;
    float matriz[4][7],menor,MINMAX;
    for (i=0;i<4;i++)
    {
        for (j=0;j<7;j++)
        {
            printf("Digite o %d elemento da %d linha:",j+1,i+1);
            scanf("%f",&matriz[i][j]);
            if (i==0 && j==0)
            {
                menor = matriz[i][j];
                menor_l = i;
            }
            else if (menor > matriz[i][j])
            {
                menor = matriz[i][j];
                menor_l = i;
            }
        }
        printf("\n");
    }
    for (j=0;j<7;j++)
    {
        if (j==0)
        {
            MINMAX = matriz[menor_l][j];
            coluna = j+1;
        }
        if (MINMAX < matriz[menor_l][j])
        {
            MINMAX = matriz[menor_l][j];
            coluna = j+1;
        }
    }
    printf("\nO MINMAX = %.2f Sua posicao = %dX%d",MINMAX,menor_l+1,coluna);
    return 0;
}