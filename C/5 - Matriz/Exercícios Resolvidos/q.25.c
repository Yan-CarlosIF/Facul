#include <stdio.h>
#define meses 2
#define prod 2
#define lojas 2

int main() {
    int i,j,k,vendas[meses][prod][lojas],bimestre[prod][lojas] = {0},maiorBi[3] = {0},vendas_lojas[lojas] = {0},vendas_prod[prod] = {0};

    for (i = 0; i < meses; i++) 
    {
        printf("\n%d mês:\n",i+1);
        for (j = 0; j < prod; j++) 
        {
            for (k = 0; k < lojas; k++) 
            {
                printf("\nInsira a quantidade de vendas do %d produto na %d loja:",j+1,k+1);
                scanf("%d",&vendas[i][j][k]);
                bimestre[j][k] += vendas[i][j][k];
            }
            printf("\n");
        }
    } 

    for (i = 0; i < prod; i++) 
    {
        for (j = 0; j < lojas; j++) 
        {
            if (maiorBi[0] < bimestre[i][j]) {
                maiorBi[0] = bimestre[i][j];
                maiorBi[1] = i+1;
                maiorBi[2] = j+1;
            }
        }
    }

    for (i = 0; i < prod; i++) 
    {
        printf("\nVendas do Produto %d no Bimestre:\n",i+1);
        for (j = 0; j < lojas; j++) 
        {
            printf("Na loja %d: %d\n",j+1,bimestre[i][j]);
        }
    }

    printf("\nA maior venda do Bimestre foi o produto %d na loja %d, com um total de: %d\n",maiorBi[1],maiorBi[2],maiorBi[0]);

    printf("\nTotal de vendas por loja:\n");
    for (i = 0; i < lojas; i++) 
    {
        for (j = 0; j < prod; j++) 
        {
            vendas_lojas[i] += bimestre[j][i];
        }
        printf("\nTotal de vendas da %d loja: %d\n",i+1,vendas_lojas[i]);
    }

    printf("\nTotal de vendas por produto:\n");
    for (i = 0; i < prod; i++) 
    {
        for (j = 0; j < lojas; j++) 
        {
            vendas_prod[i] += bimestre[i][j];
        }
        printf("\nTotal de vendas do %d produto: %d\n",i+1,vendas_prod[i]);
    }
    
    return 0;
}