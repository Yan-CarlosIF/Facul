#include <stdio.h>
#include <stdbool.h>
#define tam 10

bool jaExisteNoArr(int *arr, const int size, const int value);
void imprimirVetor(int *arr, const int size);

int main(){
    int X[tam] = {3, 8, 4, 2, 1, 6, 8, 7, 11, 9}, Y[tam] = {2, 1, 5, 12, 3, 0, 1, 4, 5, 6}, uniao[tam * 2], 
    diferenca[tam * 2], soma[tam * 2], produto[tam * 2], intersec[tam * 2];

    int tamUniao = 0;
    for (int i = 0; i < tam; i++) {
        if (!jaExisteNoArr(uniao, tamUniao, X[i])) {
            uniao[tamUniao++] = X[i];
        }
    }

    for (int i = 0; i < tam; i++) {
        if (!jaExisteNoArr(uniao, tamUniao, Y[i])) {
            uniao[tamUniao++] = Y[i];
        }
    }

    printf("\nUniao sem repeticao de X e Y: ");
    imprimirVetor(uniao, tamUniao);

    int tamDiferenca = 0;
    for (int i = 0; i < tam; i++) {
        bool encontrado = false;
        for (int j = 0; j < tam; j++) {
            if (X[i] == Y[j]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado && !jaExisteNoArr(diferenca, tamDiferenca, X[i])) {
            diferenca[tamDiferenca++] = X[i];
        }
    }

    printf("\nDiferenca de X e Y: ");
    imprimirVetor(diferenca, tamDiferenca);

    for (int i = 0; i < tam; i++) {
        soma[i] = X[i] + Y[i];
        produto[i] = X[i] * Y[i];
    }

    printf("\nSoma de X e Y: ");
    imprimirVetor(soma, tam);

    printf("\nProduto de X e Y: ");
    imprimirVetor(produto, tam);

    int tamIntersec = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (X[i] == Y[j]) {
                intersec[tamIntersec++] = X[i];
                break;
            }
        }
    }

    printf("\nIntersecao de X e Y: ");
    imprimirVetor(intersec, tamIntersec);
    return 0;
}

bool jaExisteNoArr(int *arr, const int size, const int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
}

void imprimirVetor(int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}