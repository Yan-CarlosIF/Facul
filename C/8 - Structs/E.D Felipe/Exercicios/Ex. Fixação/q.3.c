#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que use malloc() para alocar dinamicamente um vetor de inteiros. 
// O tamanho do vetor deve ser determinado pelo usuário em tempo de execução. 
// Preencha o vetor com valores fornecidos pelo usuário e imprima os valores.

int main() {
    int tam;

    printf("Digite o tam do array:");
    scanf("%d", &tam);

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