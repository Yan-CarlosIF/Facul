#include <stdio.h>

#define vendedores 5
#define semanas 4
int main() {
    int i,j,vendas[vendedores][semanas],vendas_mes[vendedores] = {0},vendas_semanas[4] = {0},vendas_total = 0;

    for (i = 0; i < 5; i++) {
        printf("vendedor %d:\n\n",i+1);
        for (j = 0; j < 4; j++) {
            printf("Digite as vendas da %d semana:",j+1);
            scanf("%d",&vendas[i][j]);
            vendas_mes[i] += vendas[i][j];
            vendas_total += vendas[i][j];
        }
        printf("\n");
    }

    printf("\nTotal de vendas no mês de cada vendedor:\n");
    for (i = 0; i < vendedores; i++) {
        printf("Vendedor %d:\nTotal de vendas: %d\n\n",i+1,vendas_mes[i]);
    }

    for (j = 0; j < semanas; j++) {
        for (i = 0; i < vendedores; i++) {
            vendas_semanas[j] += vendas[i][j];
        }
    }
    printf("\nTotal de vendas de cada semana de todos os vendedores juntos:\n");
    for (i = 0; i < semanas; i++) {
        printf("Semana %d: %d\n\n",i+1,vendas_semanas[i]);
    }
    
    printf("\nTotal de vendas do mês: %d\n",vendas_total);
    return 0;
}