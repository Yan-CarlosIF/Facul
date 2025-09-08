#include <stdio.h>
#include <stdlib.h>

int *sortAsc(int *vet, const int size) {
  int *sortedArr = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    sortedArr[i] = vet[i];
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i - 1; j++) {
      if (sortedArr[i] < sortedArr[j]) {
        int aux = sortedArr[i];
        sortedArr[i] = sortedArr[j];
        sortedArr[j] = aux;
      }
    }
  }

  return sortedArr;
}

int main() {
  int vet[] = {5, 4, 3, 2, 1};
  const int size = sizeof(vet) / sizeof(vet[0]);

  int *sortedArr = sortAsc(vet, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", sortedArr[i]);
  }

  return 0;
}