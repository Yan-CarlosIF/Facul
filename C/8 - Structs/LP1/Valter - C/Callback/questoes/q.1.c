// Questão 1:
// Crie uma função chamada transforma que recebe um vetor de
// inteiros, seu tamanho e um callback que realiza uma operação
// matemática sobre cada elemento do vetor. O vetor deve ser
// modificado diretamente pela função. Teste transforma com
// diferentes callbacks, como dobrar os valores, calcular o
// quadrado de cada número e inverter o sinal dos elementos.

#include <stdio.h>

typedef int (*Operation)(int);

void transforma(int *arr, const int tam, Operation operation) {
  for (int i = 0; i < tam; i++) arr[i] = operation(arr[i]);
}

int dobra(int valor) { return valor * 2; }

int quadrado(int valor) { return valor * valor; }

int inverteSinal(int valor) { return valor * -1; }

void exibeArr(int arr[], const int tam) {
  printf("\nVetor: ");
  for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tam = sizeof(arr) / sizeof(arr[0]);

  exibeArr(arr, tam);

  transforma(arr, tam, dobra);
  exibeArr(arr, tam);

  transforma(arr, tam, quadrado);
  exibeArr(arr, tam);

  transforma(arr, tam, inverteSinal);
  exibeArr(arr, tam);

  return 0;
}