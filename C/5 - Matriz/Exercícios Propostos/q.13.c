#include <stdio.h>

// Elabore um programa que: preencha uma matriz 6  4; recalcule a matriz
// digitada, onde cada linha de- verá ser multiplicada pelo maior elemento da
// linha em questão; mostre a matriz resultante.

int main() {
  int matrix[6][4];
  int greatestOfEveryLine[6];

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Insira o numero [%dx%d] da matriz: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);

      if (j == 0) {
        greatestOfEveryLine[i] = matrix[i][j];
      } else if (greatestOfEveryLine[i] < matrix[i][j]) {
        greatestOfEveryLine[i] = matrix[i][j];
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
        matrix[i][j] *= greatestOfEveryLine[i];
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}