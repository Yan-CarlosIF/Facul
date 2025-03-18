#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vmm;
    float p;
    printf("Digite o preco do produto:");
    scanf("%f",&p);
    printf("Digite a venda média mensal do produto:");
    scanf("%d",&vmm);

    if(vmm>=1200 && p>=80)
    {
        printf("Novo preco:%f",p-(p*0.20));
    }
    else
    {
        if(vmm>=500 && p>=30)
        {
            printf("Novo preco:%f",p+(p*0.15));
        }
        else
        {
            printf("Novo preco:%f",p+(p*0.10));
        }
    }

    return 0;
}
