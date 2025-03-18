#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que aloque memória para um vetor de inteiros, 
// preencha os valores e imprima os valores. Após o uso, libere a memória alocada com free().

int main() {
    int tam = 5;
    int *arr = (int*)malloc(sizeof(int) * tam);

    printf("\nInsira %d numeros:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}