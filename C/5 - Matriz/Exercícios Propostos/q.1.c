#include <stdio.h>

int main() {
    int i,j,x[3][5],cont = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("Digite o valor [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&x[i][j]);
            if (x[i][j] > 15 && x[i][j] < 20) {
                cont++;
            }
        }
    }

    printf("\nA quantidade de numeros entre 15 e 20 é: %d\n",cont);
    return 0;
}