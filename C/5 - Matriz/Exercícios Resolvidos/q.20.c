#include <stdio.h>

int main() {
    int i,j,matriz[5][4];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o [%dx%d] elemento da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            for (int k = i; k < 5; k++) {
                for (int l = j; l < 4; l++) {
                    if (matriz[i][j] > matriz[k][l]) {
                        int aux = matriz[i][j];
                        matriz[i][j] = matriz[k][l];
                        matriz[k][l] = aux;
                    }
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}