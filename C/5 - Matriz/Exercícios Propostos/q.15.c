#include <stdio.h>
#define LINES 12
#define COLS 13

// Crie um programa que preencha uma matriz 12  13 e divida todos os
// elementos de cada linha pelo maior elemento em módulo daquela linha. O
// programa deverá escrever a matriz lida e a modificada.

int main() {
  float matrix[LINES][COLS];
  float greatestOfEveryLine[LINES] = {0};

  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("Insira o numero [%dx%d] da matriz: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);

      float moduleValue = matrix[i][j] < 0 ? matrix[i][j] * -1 : matrix[i][j];

      if (j == 0) {
        greatestOfEveryLine[i] = moduleValue;
      } else if (greatestOfEveryLine[i] < moduleValue) {
        greatestOfEveryLine[i] = moduleValue;
      }
    }
  }

  printf("\nMatriz Lida: \n");
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz Modificada: \n");
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix[i][j] /= greatestOfEveryLine[i];
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}