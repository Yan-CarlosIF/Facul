#include <stdio.h>

void trocaValor(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particao(int *arr, int inicio, int fim) {
    int pivo = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocaValor(&arr[i], &arr[j]);
        }
    }

    trocaValor(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void quickSort(int *arr, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particao(arr, inicio, fim);

        quickSort(arr, inicio, indicePivo - 1);
        quickSort(arr, indicePivo + 1, fim);
    }
}

int main() {
    int arr[] = {3, 5, 2, 4, 6, 8, 7, 1};
    int tam = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, tam - 1);

    printf("Array ordenado:");
    for (int i = 0; i < tam; i++)
        printf("%d ", arr[i]);
    
    return 0;
}