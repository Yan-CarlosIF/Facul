#include <stdio.h>
#define lin 15
#define col 5
int main() {
    int i,j,ma[lin][col],cont[lin*col] = {0};

    for (i=0;i<lin;i++) {
        for (j=0;j<col;j++) {
            printf("digite o %d numero da %d linha:", j+1, i+1);
            scanf("%d",&ma[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            int num = ma[i][j];
            cont[num]++;
        }
    }

    printf("\nElementos que se repetem:\n");
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            int num = ma[i][j];
            if (cont[num] > 1) {
                printf("O numero %d se repetiu %d vezes\n", num, cont[num]);
                cont[num] = 1;
            }
        }
    }
    return 0;
}       
