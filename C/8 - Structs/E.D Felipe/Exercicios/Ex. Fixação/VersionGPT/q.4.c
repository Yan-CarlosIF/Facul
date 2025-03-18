#include <stdio.h>
#include <stdlib.h>

// Realocação Dinâmica e Remoção de Elementos:

// Alocar dinamicamente um vetor de inteiros e preencher os valores com números aleatórios.
// Use realloc() para diminuir o tamanho do vetor pela metade, excluindo os últimos elementos.
// Imprima o vetor antes e depois da redução.

int main() {
    int *arr = (int *)calloc(6, sizeof(int));

    arr = (int *)realloc(arr, sizeof(int) * 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}