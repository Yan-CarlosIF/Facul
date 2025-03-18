#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,cont10=0,cont20=0,cont30=0,cont31=0;
    float peso,media_10=0,media_20=0,media_30=0,media_31=0;
    for (i = 1; i <=15; i++)
    {
        printf("\nDigite a idade da %d pessoa:",i);
        scanf("%d",&idade);
        printf("\nDigite o peso da %d pessoa:",i);
        scanf("%f",&peso);
        if (idade<=10)
        {
            media_10+=peso;
            cont10++;
        }
        else if (idade<=20)
        {
            media_20+=peso;
            cont20++;
        }
        else if (idade<=30)
        {
            media_30+=peso;
            cont30++;
        }
        else
        {
            media_31+=peso;
            cont31++;
        }
    }
    printf("\nA media de peso da 1 faixa etaria: %.3f",media_10/(float)cont10);
    printf("\nA media de peso da 2 faixa etaria: %.3f",media_20/(float)cont20);
    printf("\nA media de peso da 3 faixa etaria: %.3f",media_30/(float)cont30);
    printf("\nA media de peso da 4 faixa etaria: %.3f",media_31/(float)cont31);
    return 0;
}