#include <stdio.h>

int main() {
    int i,j;
    float vendas[12][4],vendas_mes[12] = {0},vendas_ano = 0,vendas_semanas[4] = {0};
    char *mes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    for (i = 0; i < 12; i++) {
        printf("\nNo mês %d %s\n",i+1,mes[i]);
        for (j = 0; j < 4; j++) {
            printf("Digite as vendas na %d semana:",j+1);
            scanf("%f",&vendas[i][j]);
            vendas_mes[i] += vendas[i][j];
            vendas_ano += vendas[i][j];
            vendas_semanas[j] += vendas[i][j];
        }
    }
    printf("\n\nRelatorio de vendas nos mêses:\n");
    for(i = 0; i < 12; i++) {
        printf("Em %s foi vendido %.1f\n",mes[i],vendas_mes[i]);
    }
    printf("\n\nRelatorio de vendas nas semanas:\n");
    for(i = 0; i < 4; i++) {
        printf("Na %d semana durante todo o ano foi vendido %.1f\n",i+1,vendas_semanas[i]);
    }
    printf("\n\nNo ano inteiro foi vendido %.1f\n",vendas_ano);
    return 0;
}