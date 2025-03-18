#include <stdio.h>
/*Faça um programa que preencha um vetor com os modelos de cinco carros (exemplos de modelos: Fusca, 
Gol, Vectra etc). Carregue outro vetor com o consumo desses carros, isto é, quantos quilômetros cada um 
deles faz com um litro de combustível. Calcule e mostre:
 ■ o modelo de carro mais econômico; e
 ■ quantos litros de combustível cada um dos carros cadastrados consome para percorrer uma distân
cia de 1.000 km. */
#include <string.h>

int main()
{
    char modelo[5][20],*eco_nome;
    float km[5],eco_km;
    int i;
    for (i=0;i<5;i++)
    {
        printf("Digite o modelo do carro %d:",i+1);
        fflush(stdin);
        fgets(modelo[i],sizeof(modelo),stdin);
        modelo[i][strcspn(modelo[i],"\n")]='\0';
        printf("Digite quantos km por litro %s faz:",modelo[i]);
        scanf("%f",&km[i]);
        printf("\n");
        if (i==0)
        {
            eco_km=km[i];
            eco_nome=modelo[i];
        }
        if (eco_km > km[i])
        {
            eco_km=km[i];
            eco_nome=modelo[i];
        }
    }
    printf("\n%s eh o modelo de carro mais economico com %.1f KM por litro\n\n",eco_nome,eco_km);
    for (i=0;i<5;i++)
    {
        printf("O carro %s gasta %.1fL para percorrer 1000 Km\n",modelo[i],1000/km[i]);
    }
    return 0;
}