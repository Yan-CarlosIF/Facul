#include <stdio.h>

// Elabore um programa que preencha uma matriz 4  5, calcule e mostre um
// vetor com cinco posições, onde cada posição contém a soma dos elementos de
// cada coluna da matriz. O programa deverá mostrar apenas os elementos do vetor
// maiores que dez. Se não existir nenhum elemento maior que dez, deverá mostrar
// uma mensagem.

int main() {
  int matriz[4][5], vet[5] = {0};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      printf("[%dx%d]: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
      vet[j] += matriz[i][j];
    }
  }

  int elementoMaiorQue10 = 0;

  for (int i = 0; i < 5; i++) {
    if (vet[i] > 10) {
      elementoMaiorQue10 = 1;
      printf("elemento %d: %d\n", i + 1, vet[i]);
    }
  }

  if (!elementoMaiorQue10) {
    printf("Não existe nenhum elemento maior que 10");
  }

  return 0;
}