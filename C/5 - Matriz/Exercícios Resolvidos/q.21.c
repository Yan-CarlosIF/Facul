#include <stdio.h>

int main() {
    int i,j,linhas,colunas,soma = 0;
    do {
        printf("Digite o numero de linhas e colunas da matriz(numeros devem ser iguais):");
        scanf("%d %d", &linhas, &colunas);
        if (linhas != colunas) {
            printf("\nNumeros digitados são diferentes!\n");
        }
    } while (linhas != colunas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Insira o elemento [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
        printf("\n");
    }
    int linha_abaixo = 1;
    for (j = colunas - 1; j >= 0; j--) {
        for (i = linha_abaixo; i < linhas; i++) {
            soma += matriz[i][j];
        }
        linha_abaixo++;       
    }
    
    printf("\nSoma = %d\n",soma);
    return 0;
}