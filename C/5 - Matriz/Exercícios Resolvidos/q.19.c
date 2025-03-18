#include <stdio.h>

int main() {
    int i,j,num,matriz[5][4],total = 0,lin_par = 1,col_par = 0, lin_imp = 0,col_imp = 0;

    do {
        if (total != 20) {
            printf("Digite um numero:");
            scanf("%d",&num);
        }

        if (num % 2 == 0) {
            if (lin_par > 4) {
                printf("\nAs linhas pares estão lotadas\n");
            } else {
                matriz[lin_par][col_par] = num;
                col_par++;
                total++;
                if (col_par > 3) {
                    lin_par += 2;
                    col_par = 0;
                }
            }
        } else {
            if (lin_imp > 5) {
                printf("\nAs linhas impares estão lotadas\n");
            } else {
                matriz[lin_imp][col_imp] = num;
                col_imp++;
                total++;
                if (col_imp > 3) {
                    lin_imp += 2;
                    col_imp = 0;
                }
            }
        }

    } while (total != 20);
    printf("\nMatriz:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}