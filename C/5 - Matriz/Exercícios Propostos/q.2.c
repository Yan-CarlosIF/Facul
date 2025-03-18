#include <stdio.h>

int main() {
    int i,j,x[2][4],cont = 0,cont_par = 0,media = 0;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o valor [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&x[i][j]);
            if (x[i][j] > 12 && x[i][j] < 20) {
                cont++;
            }
            if (x[i][j] % 2 == 0) {
                cont_par++;
                media += x[i][j];
            }
        }
    }

    printf("\nA quantidade de valores entre 12 e 20: %d\n",cont);
    printf("A media dos valores pares digitados: %.1f\n",media/(float)cont_par);
    return 0;
}