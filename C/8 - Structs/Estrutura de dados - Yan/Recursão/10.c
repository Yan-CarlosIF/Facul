#include <stdio.h>

// Questão 10: Busca Binária Recursiva
// Implemente uma função recursiva buscaBinaria(int array[], int inicio, int fim, int valor) 
// que realize a busca binária em um array ordenado e retorne o índice do valor no array ou -1 se ele não for encontrado.

// Dica: Divida o array no meio a cada chamada. Se valor for maior que o valor central, continue a busca na metade direita; caso contrário, 
// continue na metade esquerda.

int buscaBinaria(int *arr, int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;
    
    if (arr[meio] == valor) {
        return meio;
    } else if (arr[meio] < valor) {
        return buscaBinaria(arr, meio + 1, fim, valor);
    } else {
        return buscaBinaria(arr, inicio, meio - 1, valor);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tam = sizeof(arr) / sizeof(arr[0]);
    int valor = 8;

    printf("Busca de %d, indice: %d", valor, buscaBinaria(arr, 0, tam - 1, valor));
    return 0;
}