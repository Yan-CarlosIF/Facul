#include <stdio.h>
#include <stdlib.h>

int main() {
  int **matriz = (int **)malloc(sizeof(int *) * 5);

  for (int i = 0; i < 5; i++) {
    matriz[i] = (int *)malloc(sizeof(int) * 4);
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Digite o [%dx%d] elemento da matriz:", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}