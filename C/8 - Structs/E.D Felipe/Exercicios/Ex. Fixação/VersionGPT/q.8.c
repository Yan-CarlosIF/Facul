#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Contagem de Elementos Diferentes em um Vetor usando Ponteiros:

// Declare um vetor de inteiros com alguns valores repetidos.
// Use um ponteiro para percorrer o vetor e contar quantos elementos únicos existem (sem []).
// Imprima o número de elementos distintos.

bool setted(int *set, const int tam, int element) {
    for (int i = 0; i < tam; i++) {
        if (element == *(set + i)) {
            return true;
        }    
    }

    return false;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 5};
    const int tam = sizeof(arr) / sizeof(*arr);
    int *set = (int *)malloc(sizeof(int) * tam), cont = 0;

    for (int i = 0; i < tam; i++) {
        if (!setted(set, cont, arr[i])) {
            *(set + cont) = arr[i];
            cont++;
        }
    }

    printf("\nNumero de elementos distintos: %d", cont);

    printf("\nArray Setted: ");
    for (int i = 0; i < cont; i++) {
        printf("%d ", *(set + i));
    }

    free(set);
    
    return 0;
}