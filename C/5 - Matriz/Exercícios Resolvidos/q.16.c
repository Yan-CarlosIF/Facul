#include <stdio.h>

int main() {
    int i,j,matriz[7][7],VetorMaiorLin[7] = {0},VetorMenorCol[7] = {0};
    
    printf("Preencha a matriz 7x7:\n");
    for (i = 0; i < 7; i++) {
        for (j = 0;j < 7; j++) {
            printf("Preencha o elemento [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (j == 0) {
                VetorMaiorLin[i] = matriz[i][j];
            } else if (VetorMaiorLin[i] < matriz[i][j]) {
                VetorMaiorLin[i] = matriz[i][j];
            }
        }
    }

    for (j = 0; j < 7; j++) {
        for (i = 0; i < 7; i++) {
            if (i == 0) {
                VetorMenorCol[j] = matriz[i][j];
            } else if (VetorMenorCol[i] > matriz[i][j]) {
                VetorMenorCol[j] = matriz[i][j];
            }
        }
    }
    printf("\nMatriz:\n");
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor com os maiores de cada linha:\n");
    for (i = 0; i < 7; i++) {
        printf("Linha %d = %d\n",i+1,VetorMaiorLin[i]);
    }

    printf("\nVetor com os menores de cada coluna:\n");
    for (i = 0; i < 7; i++) {
        printf("Coluna %d = %d\n",i+1,VetorMenorCol[i]);
    }
    return 0;
}