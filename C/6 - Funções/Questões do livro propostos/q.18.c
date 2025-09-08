#include <stdio.h>
#include <stdlib.h>

int menorDiagonalSecundaria(int (*matrix)[6]) {
  int menor = matrix[5][5];
  int j = 0;

  for (int i = 5; i >= 0; i--) {
    if (menor > matrix[j][i]) {
      menor = matrix[j][i];
    }

    j++;
  }

  return menor;
}

int main() {
  int matrix[6][6] = {
      {1, 2, 3, 4, 5, 6},       {7, 8, 9, 10, 11, 12},
      {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24},
      {25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36},
  };

  printMatriz(matrix);

  printf("\nMenor: %d\n", menorDiagonalSecundaria(matrix));

  return 0;
}
