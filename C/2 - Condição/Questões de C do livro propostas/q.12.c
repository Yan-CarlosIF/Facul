#include <stdio.h>

int main()
{
    float sb,sbg;
    printf("Digite o salario bruto");
    scanf("%f",&sb);

    if (sb<=350)
    {
        sbg=sb+100;
        printf("\nSeu novo salario eh:%.2f\n",sbg-(sbg*0.07));
    }
    else
    {
        if (sb<600)
        {
            sbg=sb+75;
            printf("\nSeu novo salario eh:%.2f\n",sbg-(sbg*0.07));
        }
        else
        {
            if (sb<=900)
            {
                sbg=sb+50;
                printf("\nSeu novo salario eh:%.2f\n",sbg-(sbg*0.07));
            }
            else
            {
                sbg=sb+35;
                printf("\nSeu novo salario eh:%.2f\n",sbg-(sbg*0.07));
            }   
        }
    }
    return 0;
}