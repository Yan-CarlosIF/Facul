#include <stdio.h>

// Faça um programa que preencha uma matriz 3  3 com números reais e outro
// valor numérico digitado pelo usuário. O programa deverá calcular e mostrar a
// matriz resultante da multiplicação do número digitado por cada elemento da
// matriz

int main() {
  float matrix[3][3];
  float numericValue;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Insira o numero [%dx%d] da matriz: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nInsira um valor numerico: ");
  scanf("%f", &numericValue);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] *= numericValue;
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}