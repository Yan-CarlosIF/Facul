#include <stdio.h>
/* Faça um programa que receba a temperatura média de cada mês do ano, armazenando-as em um vetor. 
Calcule e mostre a maior e a menor temperatura do ano e em que mês ocorreram (mostrar o mês por 
extenso: 1 – janeiro, 2 – fevereiro...). Desconsidere empates.*/
int main()
{
    float temp[12],maior,menor;
    int i;
    char *mes[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"},*mes_maior,*mes_menor;

    for (i = 0; i < 12; i++)
    {
        printf("Digite a media da temperatura do mes %d:",i+1);
        scanf("%f",&temp[i]);
        if (i==0)
        {
            maior=temp[i];
            menor=temp[i];
            mes_maior=mes[i];
            mes_menor=mes[i];
        }
        if (maior < temp[i])
        {
            maior=temp[i];
            mes_maior=mes[i];
        }
        if (menor > temp[i])
        {
            menor=temp[i];
            mes_menor=mes[i];
        }
    }
    printf("\nEm %s teve o maior temperatura do ano de %.1f\n",mes_maior,maior);
    printf("\nEm %s teve o menor temperatura do ano de %.1f\n",mes_menor,menor);
    return 0;
}