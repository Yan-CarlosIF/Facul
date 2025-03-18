#include <stdio.h>

int main() {
    int i,j,it,vet[18],matriz[3][6];

    printf("Digite 18 numeros:\n");
    for (i = 0; i < 18; i++){
        scanf("%d",&vet[i]);
    }
    
    it = 0;
    for (i = 0; i < 3; i++) {
        for  (j = 0; j < 6; j++) {
            matriz[i][j] = vet[it];
            it++;
        }
    }

    printf("\nMatriz Resultante:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}