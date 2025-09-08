#include <stdio.h>

int matrixSum(int (*matrix)[5], int lines, int cols) {
  int sum = 0;

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++) {
      sum += matrix[i][j];
    }
  }

  return sum;
}

int main() {
  int matrix[5][5] = {
      {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5},
  };

  int sum = matrixSum(matrix, 5, 5);

  printf("Soma da matriz: %d", sum);

  return 0;
}