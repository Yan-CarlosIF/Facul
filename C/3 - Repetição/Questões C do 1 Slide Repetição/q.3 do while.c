#include <stdio.h>

int main()
{
    int i,n,f;
    printf("Digite um numero:");
    scanf("%d",&n);
    i=1;
    f=1;

    do
    {
        printf("%d - %d\n",i,f*=i);
        i++;
    }
    while (i<=n);
    return 0;
}