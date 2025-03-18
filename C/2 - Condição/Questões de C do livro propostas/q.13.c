#include <stdio.h>

int main()
{
    float pp,np;
    printf("Digite o preco do produto:");
    scanf("%f",&pp);
    if (pp<=50)
    {
        np=pp+(pp*0.05);
    }
    else
    {
        if (pp<=100)
        {
            np=pp+(pp*0.10);
        }
        else
        {
            np=pp+(pp*0.15);
        }
    }

    if (np<=80)
    {
        printf("\nO produto de preco %.2f eh um produto de preco barato!\n",np);
    }
    else
    {
        if (np<=120)
        {
            printf("\nO produto de preco %.2f eh um produto de preco Normal\n",np);
        }
        else
        {
            if (np<=200)
            {
                printf("\nO produto de preco %.2f eh um produto de preco Caro!\n",np);
            }
            else
            {
                printf("\nO produto de preco %.2f eh um produto de preco Muito caro!\n",np);
            }
        }
    }
        
    
    return 0;
}