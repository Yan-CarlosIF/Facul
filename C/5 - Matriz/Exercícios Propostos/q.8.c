#include <stdio.h>
#define LIN 2
#define COL 2

void imprimeMatriz(int arr[LIN][COL]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr1[LIN][COL], arr2[LIN][COL], soma[LIN][COL] = {0}, diferenca[LIN][COL] = {0};

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Digite o valor [%d][%d] do primeiro array: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Digite o valor [%d][%d] do segundo array: ", i, j);
            scanf("%d", &arr2[i][j]);
        
            soma[i][j] = arr1[i][j] + arr2[i][j];
            diferenca[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    printf("\nSoma:\n");
    imprimeMatriz(soma);

    printf("\nDiferenca:\n");
    imprimeMatriz(diferenca);

    return 0;
}