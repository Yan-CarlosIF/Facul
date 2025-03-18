#include <stdio.h>
#include <stdlib.h>

int main()
{
    float b,h;
    printf("Digite o valor da base:");
    scanf("%f",&b);
    while (b==0)
    {
        printf("\nDigite um valor != de 0 para a base:");
        scanf("%f",&b);
    }
    printf("\nDigite o valor da altura:");
    scanf("%f",&h);
    while (h==0)
    {
        printf("\nDigite um valor != de 0 para a altura:");
        scanf("%f",&h);
    }
    printf("\nA area do triangulo: %.3f",(b*h)/2);
    return 0;
}