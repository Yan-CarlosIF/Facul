#include <stdio.h>

int buscaBinaria(int *arr, int num, const int size) {
  int inicio = 0;
  int fim = size - 1;

  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if (arr[meio] == num) {
      return meio;
    } else if (arr[meio] < num) {
      inicio = meio + 1;
    } else if (arr[meio] > num) {
      fim = meio - 1;
    }
  }

  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int tam = sizeof(arr) / sizeof(arr[0]);
  int numero = 3;

  int resultado = buscaBinaria(arr, numero, tam);

  printf("Indice do num %d: %d", numero, resultado);

  return 0;
}
