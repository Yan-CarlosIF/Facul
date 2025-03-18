#include <stdio.h>
#define lin 8
#define col 8

int main () {
    int i,j,A[lin][col],flag;

    for (i = 0; i < lin; i++) {
        for (j=0;j<col;j++) {
            printf("Digite [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
        printf("\n");
    }
    flag = 1;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            if (A[i][j] != A[j][i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    
    if (!flag) {
        printf("\nA matriz nao eh simetrica!\n");
    } else {
        printf("\nA matriz eh simetrica!\n");
    }
    return 0;
}