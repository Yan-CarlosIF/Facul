#include <stdio.h>

int main() {
  int matriz[5][4] = {{10, 1, 2, 20},
                      {30, 17, 98, 65},
                      {24, 12, 5, 8},
                      {73, 55, 31, 100},
                      {120, 110, 114, 130}};

  int vector[5 * 4], size = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      vector[size++] = matriz[i][j];
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (vector[i] < vector[j]) {
        int aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }

  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      matriz[i][j] = vector[k++];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", matriz[i][j]);
    }

    printf("\n");
  }

  return 0;
}