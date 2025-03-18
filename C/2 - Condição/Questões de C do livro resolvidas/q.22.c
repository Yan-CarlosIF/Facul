#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sb,sl,i;
    int ts;

    printf("Digite o salario base:");
    scanf("%f",&sb);
    printf("\nDigite em anos o tempo de servico:");
    scanf("%d",&ts);

    if (sb>=700)
    {
        i=sb*0.12;
    }
    else
    {
        if (sb>450)
        {
            i=sb*0.08;
        }
        else
        {
            if(sb>=200)
            {
                i=sb*0.03;
            }
            else
            {
                i=sb*0;
            }
        }
    }
    if (sb>500)
    {
        if(ts<=3)
        {
            sl=(sb-i)+20;
        }
        else
        {
          sl=(sb-i)+30;
        }
    }
    if (sb<=500)
    {
        if (ts<=3)
        {
            sl=(sb-i)+23;
        }
        else
        {
            if (ts<=6)
            {
                sl=(sb-i)+35;
            }
            else
            {
                sl=(sb-i)+33;
            }
            
        }
        
    }
    
    if (sl<=350)
    {
        printf("Seu salario liquido e de:%.2f e esta categorizado como A!",sl);
    }
    else if (sl<600)
    {
        printf("Seu salario liquido e de:%.2f e esta categorizado como B!",sl);
    }
    else
    {
        printf("Seu salario liquido e de:%.2f e esta categorizado como C!",sl);
    }
    return 0;
}