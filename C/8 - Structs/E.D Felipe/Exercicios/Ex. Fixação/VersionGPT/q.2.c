#include <stdio.h>
#include <stdlib.h>

// Inversão de Valores em Vetor com Ponteiro:

// Crie um vetor de inteiros com valores predefinidos.
// Declare um ponteiro para percorrer o vetor e inverter a ordem dos elementos (primeiro com último, segundo com penúltimo, etc.).
// Imprima o vetor antes e depois da inversão.

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ponteiroArr = arr, tam = sizeof(arr) / sizeof(*arr);

    printf("\nArray: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(ponteiroArr + i));
    }

    for (int i = 0; i < tam / 2; i++) {
        int aux = *(ponteiroArr + i);
        *(ponteiroArr + i) = *(ponteiroArr + (tam - i - 1));
        *(ponteiroArr + (tam - i - 1)) = aux;
    }

    printf("\nArray invertido: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(ponteiroArr + i));
    }

    return 0;
}