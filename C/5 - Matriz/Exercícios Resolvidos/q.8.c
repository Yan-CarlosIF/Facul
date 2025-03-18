#include <stdio.h>

int main(){
    int i,j,matriz[6][4],matrizr[6][4];
    
    for (i = 0; i < 6; i++) {
        for (j = 0 ; j < 4; j++) {
            printf("Digite um numero:");
            scanf("%d",&matriz[i][j]);
        }
    }

    printf("\nElementos maiores que 30:\n");
    for ( i = 0; i < 6; i++) {
        for ( j = 0; j < 4; j++) {
            if (matriz[i][j] > 30) {
                printf("%d\n",matriz[i][j]);
            }
        }
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            if (matriz[i][j] != 30) {
                matrizr[i][j] = matriz[i][j];
            } else {
                matrizr[i][j] = 0;
            }
        }
    }

    printf("\nMatriz Resultante dos numeros diferentes de 30:\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",matrizr[i][j]);
        }
        printf("\n");
    }
    return 0;
}