#include <stdio.h>

int main()
{
    int x,y,i,resultado=1;
    printf("Digite o valor x:");
    scanf("%d",&x);
    printf("\nDigite o quanto deseja elevar o numero x:");
    scanf("%d",&y);

    for (i = 1; i <= y;i++)
    {
        resultado*=x;
    }
    printf("\n%d",resultado);
    return 0;
}