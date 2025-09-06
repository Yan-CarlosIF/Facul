#include <stdio.h>
#include <stdlib.h>

int* sortArray(int* arrayA, int size) {
  int* sortedArray = (int*)malloc(sizeof(int) * 5);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i - 1; j++) {
      if (arrayA[i] < arrayA[j]) {
        int aux = arrayA[i];
        arrayA[i] = arrayA[j];
        arrayA[j] = aux;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    sortedArray[i] = arrayA[i];
  }

  return sortedArray;
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};

  const int* sorted = sortArray(arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", sorted[i]);
  }

  return 0;
}