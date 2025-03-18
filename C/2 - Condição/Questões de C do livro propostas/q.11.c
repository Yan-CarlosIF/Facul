#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s;
    printf("Digite seu salario:");
    scanf("%f",&s);

    if (s<300)
    {
        printf("\nO valor do aumento %.2f e o novo salario %.2f\n",s*0.15,s+(s*0.15));
    }
    else
    {
        if (s<600)
        {
            printf("\nO valor do aumento %.2f e o novo salario %.2f\n",s*0.10,s+(s*0.10));
        }
        else
        {
            if (s<=900)
            {
                printf("\nO valor do aumento %.2f e o novo salario %.2f\n",s*0.05,s+(s*0.05));
            }
            else
            {
                printf("\nO valor do aumento %.2f e o novo salario %.2f\n",s*0,s);
            }
        }
    }
    return 0;
}