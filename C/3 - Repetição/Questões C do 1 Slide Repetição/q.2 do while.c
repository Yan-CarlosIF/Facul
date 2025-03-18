#include <stdio.h>

int main()
{
    int i,n;
    printf("Digite o numero que deseja calcular o fatorial:");
    scanf("%d",&n);
    i=n;
    do
    {
        i--;
        n*=i;
    }
    while(i>1);
    printf("O fatorial eh %d",n);
    return 0;
}