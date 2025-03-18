#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,cont_90=0,cont_i=0,cont_a=0;
    float peso,altura,media_i=0;
    for (i = 1; i <=10; i++)
    {
        printf("\nDigite a %d idade:",i);
        scanf("%d",&idade);
        printf("\nDigite a %d peso:",i);
        scanf("%f",&peso);
        printf("\nDigite a %d altura:",i);
        scanf("%f",&altura);
        media_i+=idade;
        if (peso>90 && altura<1.50)
        {
            cont_90++;
        }
        if (altura>1.90)
        {
            cont_a++;
            if (idade>=10 && idade <=30)
            {
                cont_i++;
            }
        }
    }
    printf("\nA media das idades das dez pessoas: %.1f",media_i/10);
    printf("\nA quantidade de pessoas com peso superior a 90 kg e altura inferior a 1,50 metros: %d",cont_90);
    printf("\nA porcentagem de pessoas com idade entre 10 e 30 anos entre as pessoas que medem mais de 1,90 m: %.1f%%",(cont_i/(float)cont_a)*100);
    return 0;
}