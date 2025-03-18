#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,cont_ip=0,cont_oa=0,cont_r=0,cont_15=0;
    float altura,peso,idadetotal_15=0;
    char cor_o,cor_c;
    for (i = 1; i <=6 ; i++)
    {
        printf("\nDigite a idade da pessoa %d:",i);
        scanf("%d",&idade);
        printf("\nDigite o peso da pessoa %d:",i);
        scanf("%f",&peso);
        printf("\nDigite a altura da pessoa %d:",i);
        scanf("%f",&altura);
        do
        {
            printf("\nDigite a cor do olho da pessoa %d:",i);
            fflush(stdin);
            scanf("%c",&cor_o);
        } while(cor_o != 'A' && cor_o != 'P' && cor_o != 'V' && cor_o != 'C');
        do
        {
            printf("\nDigite a cor do cabelo da pessoa %d:",i);
            fflush(stdin);
            scanf("%c",&cor_c);
        } while (cor_c != 'L' && cor_c != 'P' && cor_c != 'R' && cor_c != 'C');
        if (idade>50 && peso<60)
        {
            cont_ip++;
        }
        if (altura<1.5)
        {
            idadetotal_15+=idade;
            cont_15++;
        }
        if (cor_o == 'A')
        {
            cont_oa++;
        }
        if (cor_c == 'R' && cor_o != 'A')
        {
            cont_r++;
        }
    }
    printf("\nA quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 kg: %d",cont_ip);
    printf("\nA media das idades das pessoas com altura inferior a 1,50 m: %.1f",idadetotal_15/cont_15);
    printf("\nA porcentagem de pessoas com olhos azuis entre todas as pessoas analisadas: %.1f",(cont_oa/(float)6)*100);
    printf("\nA quantidade de pessoas ruivas e que não possuem olhos azuis: %d",cont_r);
    return 0;
}