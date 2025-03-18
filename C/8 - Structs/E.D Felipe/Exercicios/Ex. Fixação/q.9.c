#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que conte quantos elementos existem em um vetor usando apenas 
// ponteiros (sem usar a notação de vetores com [ ] diretamente). Imprima o número de elementos.

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tam = sizeof(arr) / sizeof(*arr);

    printf("\n%d / %d\n", sizeof(arr), sizeof(*arr));
    printf("O vetor tem %d elementos.\n", tam);
    
    return 0;
}