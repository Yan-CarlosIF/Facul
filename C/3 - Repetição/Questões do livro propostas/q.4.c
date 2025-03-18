#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,m;
    printf("Digite um numero que deseja saber a tabuada:\n");
    scanf("%d",&n);
    printf("A tabuada de %d:\n",n);
    for (i=1;i<=10;i++)
    {
        m=n*i;
        printf("%d x %d = %d:\n",n,i,m);
    }
    return 0;
}