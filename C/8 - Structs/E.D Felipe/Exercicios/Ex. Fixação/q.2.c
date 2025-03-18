#include <stdio.h>

// Crie um programa que tenha um vetor de inteiro. Você pode definir os valores a mão. 
// Declare um ponteiro e use esse ponteiro para percorrer e modificar os elementos do vetor, 
// os substituindo pelo valor do resto da divisão de cada elemento por 2. Após a modificação, imprima o vetor.

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int tam = sizeof(arr) / sizeof(arr[0]);

    int *enderecoArray = arr;

    for (int i = 0; i < tam; i++) {
        *(enderecoArray + i) = *(enderecoArray + i) % 2;
    }

    printf("\nArray modificado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(enderecoArray + i));
    }
    
    return 0;
}