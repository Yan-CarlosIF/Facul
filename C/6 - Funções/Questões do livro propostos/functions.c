#include <stdio.h>

void printMatriz(int (*matrix)[6]) {
  printf("Matriz:\n");
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
