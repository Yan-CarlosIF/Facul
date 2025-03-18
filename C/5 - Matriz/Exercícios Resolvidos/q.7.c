#include <stdio.h>
#define lin 5
#define col 7

int main() {
    int i, j, k, ColunaMenor, possui;
    float MatrizA[lin][col], menor;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Digite o %d elemento da %d linha: ", j + 1, i + 1);
            scanf("%f", &MatrizA[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < lin; i++) {
        possui = 1;
        menor = MatrizA[i][0];
        ColunaMenor = 0;
        for (j = 0; j < col; j++) {
            if (menor > MatrizA[i][j]) {
                menor = MatrizA[i][j];
                ColunaMenor = j;
            }
        }

        for (k = 0; k < lin; k++) {
            if (MatrizA[k][ColunaMenor] > menor) {
                possui = 0;
                break;
            }
        }
    }
    if (possui) {
        printf("O ponto de sela do array eh %.1f, e se localiza na linha %d na coluna %d\n", menor, i, ColunaMenor + 1);
    } else {
        printf("\nO array nao possui ponto de sela\n");
    }
    return 0;
}
