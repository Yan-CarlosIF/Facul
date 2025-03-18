#include <stdio.h>

// Questão 5: Maior Elemento em um Array
// Implemente uma função recursiva maiorElemento(int array[], int tamanho) que encontre o maior elemento de um array de inteiros. A função deve retornar o maior valor do array.

// Dica: Compare o primeiro elemento com o maior valor do restante do array.

int maiorElemento(int *arr, int tam) {
    if (tam == 1) {
        return arr[0];
    }
    
    int maiorRestante = maiorElemento(arr + 1, tam - 1);

    return (maiorRestante > arr[0]) ? maiorRestante : arr[0];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tam = sizeof(arr) / sizeof(arr[0]);
    int maior = maiorElemento(arr, tam);
    
    printf("Maior Elemento = %d\n", maior);
    return 0;
}