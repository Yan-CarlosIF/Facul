#include <stdio.h>
#define lin 10
#define col 10
int main() {
    int i,j,ma[lin][col];
    
    for (i=0;i<lin;i++) {
        for (j=0;j<col;j++) {
            printf("Digite o numero [%d]x[%d] da matriz:",i+1,j+1);
            scanf("%d",&ma[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Inicial\n");
    for (i=0;i<lin;i++) {
        for (j=0;j<col;j++) {
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < col; i++) {
        int aux = ma[2 - 1][i];
        ma[2 - 1][i] = ma[8 - 1][i];
        ma[8 - 1][i] = aux;
    }

    for (i = 0; i < lin; i++) {
        int aux = ma[i][4 - 1];
        ma[i][4 - 1] = ma[i][10 - 1];
        ma[i][10 - 1] = aux;
    }
    
    /* Trocando as Diagonais da matriz usando while */
    /*int l=col-1; i=0; j=0;
    while (i<lin && j<col) {
        int aux = ma[i][j];
        ma[i][j] = ma[i][l];
        ma[i][l] = aux;
        i++;
        j++;
        l--;
    }*/
    /* Trocando as Diagonais usando for (Mais Facil!) */
    for (i = 0 ; i < lin; i++) {
        int aux = ma[i][i];
        ma[i][i] = ma[i][col - 1 - i];
        ma[i][col - 1 - i] = aux;
    }
    
    for (i = 0; i < col; i++) {
        int aux = ma[5 - 1][i];
        ma[5 - 1][i] = ma[i][10 - 1];
        ma[i][10 - 1] = aux;
    }

    printf("\nMatriz Resultante\n");
    for (i=0;i<lin;i++) {
        for (j=0;j<col;j++) {
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }
    return 0;
}