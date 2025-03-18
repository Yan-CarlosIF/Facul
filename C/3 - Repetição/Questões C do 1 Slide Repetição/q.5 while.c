#include <stdio.h>

int main()
{
    int x,y,i,resultado;
    printf("Digite um numero de X:");
    scanf("%d",&x);
    printf("\nDigite um numero positivo que deseja elevar X:");
    scanf("%d",&y);
    resultado=1;
    i=1;
    while (i<=y)
    {
        resultado*=x;
        i++;
    }
    printf("\n%d",resultado);
    return 0;
}