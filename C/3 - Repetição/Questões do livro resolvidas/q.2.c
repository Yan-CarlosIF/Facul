#include <stdio.h>

int main()
{
    int i;
    float n,e=0;
    printf("Digite um numero:");
    scanf("%f",&n);

    for (i = 1; i <= n; i++)
    {
        e+=(1/(float)i);
    }
    printf("\n%f",e+1);
    return 0;
}