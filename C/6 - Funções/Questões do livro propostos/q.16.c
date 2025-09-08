#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 3

int *generateVectorC(int *vectorA, int *vectorB) {
  int *vectorC = (int *)malloc(sizeof(int) * (VECTOR_SIZE * 2));
  int j = 0;

  for (int i = 0; i < VECTOR_SIZE; i++) {
    vectorC[j++] = vectorA[i];
    vectorC[j++] = vectorB[i];
  }

  for (int i = 0; i < VECTOR_SIZE * 2; i++) {
    for (int j = 0; j < i; j++) {
      if (vectorC[i] > vectorC[j]) {
        int aux = vectorC[i];
        vectorC[i] = vectorC[j];
        vectorC[j] = aux;
      }
    }
  }

  return vectorC;
}

int main() {
  int vectorA[] = {1, 2, 3};
  int vectorB[] = {6, 2, 8};

  int *vectorC = generateVectorC(vectorA, vectorB);

  for (int i = 0; i < VECTOR_SIZE * 2; i++) {
    printf("%d ", vectorC[i]);
  }

  return 0;
}
