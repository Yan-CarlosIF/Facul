#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,m,n,soma=0;
    printf("\nDigite um numero par inteiro positivo para M:");
    scanf("%d",&m);
    printf("\nDigite um numero par inteiro positivo para N:");
    scanf("%d",&n);
    while (m<n)
    {
        for(i=m;i<=n;i++)
        {
            soma+=i;
        }
        printf("\nA soma de todos os numeros entre M e N:%d\n",soma);
        printf("\nDigite um numero par inteiro positivo para M:");
        scanf("%d",&m);
        printf("\nDigite um numero par inteiro positivo para N:");
        scanf("%d",&n);
    }
    return 0;
}