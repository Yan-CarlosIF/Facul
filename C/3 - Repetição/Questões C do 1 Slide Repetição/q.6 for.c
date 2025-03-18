#include <stdio.h>

int main()
{
    int x,y,i;
    printf("digite um numero:");
    scanf("%d",&x);
    printf("digite outro numero maior que o primeiro!:");
    scanf("%d",&y);
    printf("todos os numeros entre %d e %d sao:\n",x,y);
    for (i =x+1; i < y; i++)
    {
        printf("%d\n",i);
    }
    return 0;
}