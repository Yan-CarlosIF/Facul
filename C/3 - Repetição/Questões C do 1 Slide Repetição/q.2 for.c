#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("Digite o numero que deseja saber o fatorial:");
    scanf("%d",&n);
    for (i=1; n > 1; n--)
    {
        i*=n;
    }
    printf("%d",i);
    
    return 0;
}