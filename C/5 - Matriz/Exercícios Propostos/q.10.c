#include <stdio.h>

// Crie um programa que preencha uma matriz 5  5 com números inteiros, calcule e mostre a soma: 
// ■ dos elementos da linha 4; 
// ■ dos elementos da coluna 2; 
// ■ dos elementos da diagonal principal; 
// ■ dos elementos da diagonal secundária; 
// ■ de todos os elementos da matriz.

int main() {
  int matrix[5][5];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("Insira o valor [%dx%d]: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);  
    }
  }

  printf("\nMatriz inserida:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }


  int line4Sum = 0, col2Sum = 0, mainDiagonalSum = 0, secondDiagonalSum = 0, totalSum = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      totalSum += matrix[i][j];

      if (i == 3) {
        line4Sum += matrix[i][j];
      }

      if (j == 1) {
        col2Sum += matrix[i][j];
      }

      if (i == j) {
        mainDiagonalSum += matrix[i][j];
      }

      if (i + j == 4) {
        secondDiagonalSum += matrix[i][j];
      }
    }
  }

  printf("\nSoma dos elementos da linha 4: %d\n", line4Sum);
  printf("Soma dos elementos da coluna 2: %d\n", col2Sum);
  printf("Soma dos elementos da diagonal principal: %d\n", mainDiagonalSum);
  printf("Soma dos elementos da diagonal secundaria: %d\n", secondDiagonalSum);
  printf("Soma de todos os elementos da matriz: %d\n", totalSum);
  
  return 0;
}