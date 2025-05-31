// Questão 2:
// Implemente uma função chamada processa que recebe um vetor
// de inteiros, seu tamanho e dois callbacks: um para aplicar
// uma transformação em cada elemento do vetor e outro para
// definir uma condição de exibição na tela. O programa deve
// modificar os elementos do vetor conforme o primeiro callback
// e imprimir apenas aqueles que satisfazem o segundo callback.
// Teste a função com diferentes combinações, como dobrar os
// valores e exibir apenas os números divisíveis por 5, ou calcular
// o quadrado e exibir apenas os maiores que 50.

#include <stdbool.h>
#include <stdio.h>

typedef int(Transformacao)(int);

typedef bool(Condition)(int);

void processa(int *arr, const int tam, Transformacao transf, Condition cond) {
  printf("\nVetor: ");
  for (int i = 0; i < tam; i++) {
    arr[i] = transf(arr[i]);

    if (cond(arr[i])) printf("%d ", arr[i]);
  }
}

int dobra(int valor) { return valor * 2; }

int quadrado(int valor) { return valor * valor; }

bool divisivelPor5(int valor) { return valor % 5 == 0; }

bool maiorQue50(int valor) { return valor > 50; }

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int tam = sizeof(arr) / sizeof(arr[0]);

  processa(arr, tam, dobra, divisivelPor5);

  processa(arr, tam, quadrado, maiorQue50);

  return 0;
}