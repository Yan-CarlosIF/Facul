#include <stdio.h>

int main()
{
    int i;
    float s=1000,a=0.015;
    i=2006;
    do
    {
        printf("O seu salario no ano %d eh de %.2f\n",i,s+(s*a));
        i++;
        a=a*2;
    }
    while (i<=2024);
    return 0;
}