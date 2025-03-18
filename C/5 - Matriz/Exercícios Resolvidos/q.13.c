#include <stdio.h>
#include <string.h>

int main() {
    const int produtos = 5;
    const int lojas = 4;
    int i,j;
    char nomes_p[produtos][20];
    float precos[produtos][lojas],custo_tran[produtos],impostos[produtos][lojas],preco_final[produtos][lojas];

    for (i=0; i < produtos; i++) {
        printf("Digite o nome do %d produto:",i+1);
        fflush(stdin);
        fgets(nomes_p[i],sizeof(nomes_p),stdin);
        nomes_p[i][strcspn(nomes_p[i],"\n")]='\0';
        printf("\nDigite o custo de transporte do produto %s:",nomes_p[i]);
        scanf("%f",&custo_tran[i]);
    }

    printf("\n");
    for (i = 0; i < produtos; i++) {
        for (j = 0; j < lojas; j++) {
            do {
                printf("Digite o preco do produto %s da %d loja:",nomes_p[i],j+1);
                scanf("%f",&precos[i][j]);
            } while (precos[i][j] < 0);
        }
        printf("\n");
    }

    for (i = 0; i < produtos; i++) {
        for (j = 0; j < lojas; j++) {
            if (precos[i][j] <= 50) {
                impostos[i][j] = precos[i][j] * 0.05;
            } else if (precos[i][j] <= 100) {
                impostos[i][j] = precos[i][j] * 0.10;
            } else {
                impostos[i][j] = precos[i][j] * 0.20;
            }
            preco_final[i][j] = precos[i][j] + impostos[i][j] + custo_tran[i];
        }
    }
    printf("\nRelatorio de produtos:\n");
    for (i = 0; i < produtos; i++) {
        printf("Nome do produto: %s\n",nomes_p[i]);
        for (j = 0; j < lojas; j++) {
            printf("%d loja:\n",j+1);
            printf("Valor do imposto: %.2f\n",impostos[i][j]);
            printf("Custo de transporte: %.2f\n",custo_tran[i]);
            printf("Preco inicial: %.2f\nPreco Final: %.2f\n",precos[i][j],preco_final[i][j]);
        }
        printf("\n");
    }
    return 0;
}