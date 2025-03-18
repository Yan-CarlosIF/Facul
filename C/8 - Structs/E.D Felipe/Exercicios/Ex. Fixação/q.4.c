#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que aloque dinamicamente um vetor de inteiros e, depois, 
// redimensione esse vetor usando realloc() para aumentar seu tamanho. 
// Preencha o vetor com novos valores e imprima o conteúdo final.


int main() {
    int *arr, tam;

    printf("Digite quantas posicoes deseja alocar: ");
    scanf("%d", &tam);

    arr = (int*)malloc(sizeof(int) * tam);
    
    printf("\nInsira %d numeros:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }

    int tamRealloc;
    printf("\nDeseja realocar para um vetor de quantas posicoes: ");
    scanf("%d", &tamRealloc);

    arr = (int*)realloc(arr, sizeof(int) * tamRealloc);

    if (tamRealloc <= tam) {
        printf("\nArray realocado: ");
        for (int i = 0; i < tamRealloc; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("\nInsira mais %d numeros:\n", tamRealloc - tam);
        for (int i = tam; i < tamRealloc; i++) {
            scanf("%d", &arr[i]);
        }

        printf("\nArray realocado: ");
        for (int i = 0; i < tamRealloc; i++) {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}