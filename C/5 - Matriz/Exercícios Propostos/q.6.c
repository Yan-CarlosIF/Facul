#include <stdio.h>
#define lin 4
#define col 4
int main() {
    int i,j,matriz[lin][col],soma_col[col] = {0},matrizR[lin][col];

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Digite o valor [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
            soma_col[j] += matriz[i][j];
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            matrizR[i][j] = matriz[i][j] * soma_col[j];
        }
    }

    printf("\nMatriz Resultante:\n");
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ",matrizR[i][j]);
        }
        printf("\n");
    }
    return 0;
}