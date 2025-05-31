#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que declare uma função que some dois números.
// Em seguida, declare um ponteiro para essa função e use o ponteiro para chamar
// a função e imprimir o resultado.

int soma(int a, int b) { return a + b; }

int main() {
  int (*pSoma)(int, int) = soma;
  int x = 1, y = 2;

  printf("resultado = %d", pSoma(x, y));
  return 0;
}