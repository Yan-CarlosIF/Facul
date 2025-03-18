#include <stdio.h>

int main()
{
    int x,y,i,soma=0;
    printf("digite um numero:");
    scanf("%d",&x);
    printf("\ndigite outro numero maior que o primeiro!:");
    scanf("%d",&y);
    for (i =x+1; i < y; i++)
    {
        soma+=i;
    }
    printf("\nA soma de todos os numeros entre %d e %d eh %d",x,y,soma);
    return 0;
}