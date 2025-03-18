#include <stdio.h>

int main()
{
    float cf,pd,imp;
    printf("Digite o custo de fabrica:");
    scanf("%f",&cf);

    if (cf>25000)
    {
        pd=cf*0.15;
        imp=cf*0.20;
        printf("\nPreco ao consumidor:%.2f\n",cf+pd+imp);
    }
    else if (cf>12000)
    {
        pd=cf*0.10;
        imp=cf*0.15;
        printf("\nPreco ao consumidor:%.2f\n",cf+pd+imp);
    }
    else
    {
        pd=cf*0.05;
        imp=cf*0;
        printf("\nPreco ao consumidor:%.2f\n",cf+pd+imp);
    }
    return 0;
}