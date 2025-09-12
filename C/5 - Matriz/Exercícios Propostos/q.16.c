#include <stdio.h>

// Elabore um programa que preencha uma matriz 5  5 e crie dois vetores de
// cinco posições cada um, que contenham, respectivamente, as somas das linhas e
// das colunas da matriz. O programa deverá escrever a matriz e os vetores
// criados.

int main() {
  int matriz[5][5], somaLinhas[5] = {0}, somaColunas[5] = {0};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      somaLinhas[i] += matriz[i][j];
      somaColunas[j] += matriz[i][j];
    }
  }

  printf("\nMatriz:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%4d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nVetor soma linhas: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", somaLinhas[i]);
  }

  printf("\nVetor soma colunas: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", somaColunas[i]);
  }

  return 0;
}