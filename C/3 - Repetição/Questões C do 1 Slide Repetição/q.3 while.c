#include <stdio.h>

int main()
{
    int i,n,f;
    printf("Digite um numero:");
    scanf("%d",&n);
    i=1;
    f=1;
    while (i<=n)
    {
        printf("%d - %d\n",i,f=f*i);
        i++;
    }
    return 0;
}