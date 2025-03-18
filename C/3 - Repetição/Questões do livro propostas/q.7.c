#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,cont_50=0,cont_40=0,cont_1=0;
    float altura,peso,media=0;
    for (i = 1; i <=5; i++)
    {
        printf("\nDigite a idade da %d pessoa:",i);
        scanf("%d",&idade);
        printf("\nDigite a altura da %d pessoa:",i);
        scanf("%f",&altura);
        printf("\nDigite o peso da %d pessoa:",i);
        scanf("%f",&peso);
        if (idade>50)
        {
            cont_50++;
        }
        if (idade>=10 && idade <=20)
        {
            cont_1++;
            media+=altura;
        }
        if (peso<40)
        {
            cont_40++;
        }
    }
    printf("\nA quantidade pessoas com idade superior a 50 anos: %d",cont_50);
    printf("\nA media das alturas das pessoas com idade entre 10 e 20 anos: %.2f",media/(float)cont_1);
    printf("\nA porcentagem de pessoas com peso inferior a 40 kg entre todas as pessoas analisadas: %.1f",(cont_40/(float)5)*100);
    return 0;
}