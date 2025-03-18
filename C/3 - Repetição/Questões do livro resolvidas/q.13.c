#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,nc,contm=0,contf=0,cont24=0; float tv;
    char s;
    printf("Digite o numero de criancas nascidas:");
    scanf("%d",&nc);
    for (i = 1; i <=nc; i++)
    {
        printf("Digite o sexo da crianca %d\nM - para masculino\nF - para feminino\n:",i);
        fflush(stdin);
        scanf("%c",&s);
        while (s !='M' && s !='F')
        {
            printf("DIGITE SOMENTE M OU F para sexo da crianca %d",i);
            fflush(stdin);
            scanf("%c",&s);
        }
        if (s=='M')
        {
            contm++;
        }
        else
        {
            contf++;
        }
        printf("Digite o tempo de vida em meses da crianca %d\n:",i);
        scanf("%f",&tv);
        if (tv<=24)
        {
            cont24++;
        }   
    }
        printf("\nA porcentagem de criancas do sexo feminino mortas no periodo eh %.1f%%",(contf/(float)nc)*100);
        printf("\nA porcentagem de criancas do sexo masculino mortas no periodo eh %.1f%%",(contm/(float)nc)*100);
        printf("\nA porcentagem de criancas que viveram 24 meses ou menos no periodo eh %.1f%%",(cont24/(float)nc)*100);
    return 0;
}