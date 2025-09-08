#include <stdio.h>
#include <stdlib.h>

#define LINES 3
#define COLS 4

float *copyToVector(float (*matrix)[COLS]) {
  float *vector = (float *)malloc(sizeof(float) * (LINES * COLS));
  int k = 0;

  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      vector[k++] = matrix[i][j];
    }
  }

  return vector;
}

int main() {
  float matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  float *vector = copyToVector(matrix);

  printf("Vector: ");
  for (int i = 0; i < LINES * COLS; i++) {
    printf("%.1f ", vector[i]);
  }
  printf("\n");

  return 0;
}