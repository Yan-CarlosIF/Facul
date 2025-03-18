#include <stdio.h>

int main()
{
    int i,j;
    float M[2][2],R[2][2],maior=0;
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            printf("Digite o %d numero da %d fileira:",j+1,i+1);
            scanf("%f",&M[i][j]);
            if (maior < M[i][j])
            {
                maior = M[i][j];
            }
        }
        printf("\n");
    }
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            R[i][j] = M[i][j]*maior;
            printf("%.1f ",R[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}