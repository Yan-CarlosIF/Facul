#include <stdio.h>

int main() {
    int matriz[6][3],maior[3] = {0},menor[3];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor da posição [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
            if (maior[0] < matriz[i][j]) {
                maior[0] = matriz[i][j];
                maior[1] = i+1;
                maior[2] = j+1;
            }
            if (i == 0 && j == 0) {
                menor[0] = matriz[i][j];
                menor[1] = i+1;
                menor[2] = j+1;
            } else if (menor[0] > matriz[i][j]) {
                menor[0] = matriz[i][j];
                menor[1] = i+1;
                menor[2] = j+1;
            }
        }
    }

    printf("\nO maior valor da matriz é %d e esta na linha %d e na coluna %d\n",maior[0],maior[1],maior[2]);
    printf("\nO menor valor da matriz é %d e esta na linha %d e na coluna %d\n",menor[0],menor[1],menor[2]);
    return 0;
}