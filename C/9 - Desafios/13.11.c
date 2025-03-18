#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Faça um programa que apresente o menu de opções a seguir:
// 1. Incluir um número no vetor.
// 2. Consultar todos os números do vetor.
// 3. Consultar um número do vetor.
// 4. Excluir um número no vetor.
// 5. Esvaziar o vetor.
// 6. Sair.

// Todas as operações anteriores devem ser realizadas em um vetor de dez
// posições e o vetor pode conter números repetidos, que devem estar ordenados.

void menu(int *op);
void add(int *vet, int *index);
void exibirVet(const int *vet, const int index);
int numIsInVet(const int *vet, const int index);
void excluirNum(int *vet, int *index);
void clearVet(int *vet);

int main() {
  int vetor[SIZE], index = 0, op;

  do {
    menu(&op);

    switch (op) {
      case 1:
        add(vetor, &index);
        break;
      case 2:
        exibirVet(vetor, index);
        break;
      case 3:
        numIsInVet(vetor, index);
        break;
      case 4:
        excluirNum(vetor, &index);
        break;
      case 5:
        clearVet(vetor);
        index = 0;
        break;
      case 6:
        printf("\nSaindo...\n");
        break;
      default:
        printf("\nOpcao Invalida!\n");
        break;
    }
  } while (op != 6);

  return 0;
}

void menu(int *op) {
  printf("\nInsira:\n1. Incluir um numero no vetor.\n");
  printf("2. Consultar todos os numeros do vetor.\n");
  printf("3. Consultar um numero do vetor.\n");
  printf("4. Excluir um numero no vetor.\n");
  printf("5. Esvaziar o vetor.\n");
  printf("6. Sair.\n");
  printf("Escolha uma opcao: ");
  scanf("%d", op);
}

void add(int *vet, int *index) {
  if (*index >= SIZE) {
    printf("Vetor cheio!\n");
    return;
  }

  int num, i;
  printf("Digite o numero que deseja inserir no vetor: ");
  scanf("%d", &num);

  for (i = 0; i < *index; i++)
    if (vet[i] > num) break;

  for (int j = *index; j > i; j--) vet[j] = vet[j - 1];

  vet[i] = num;

  (*index)++;
}

void exibirVet(const int *vet, const int index) {
  if (index == 0) {
    printf("\nVetor vazio!\n");
    return;
  }

  printf("\nVetor: ");
  for (int i = 0; i < index; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}

int numIsInVet(const int *vet, const int index) {
  int num;
  printf("Digite o numero que deseja consultar: ");
  scanf("%d", &num);

  for (int i = 0; i < index; i++) {
    if (vet[i] == num) {
      printf("\nO numero %d esta no vetor!\n", num);
      return i;
    }
  }

  printf("\nO numero nao esta no vetor!\n");
  return -1;
}

void excluirNum(int *vet, int *index) {
  if (*index == 0) return;

  int num, indexSearch;
  printf("Digite o numero que deseja excluir: ");
  scanf("%d", &num);

  for (int i = 0; i < *index; i++) {
    if (vet[i] == num) {
      indexSearch = i;
      break;
    }
  }

  if (indexSearch == -1) return;

  if (indexSearch == *index - 1) {
    vet[indexSearch] = -1;
  } else {
    for (int i = indexSearch; i < *index; i++) vet[i] = vet[i + 1];
  }

  (*index)--;
}

void clearVet(int *vet) {
  for (int i = 0; i < SIZE; i++) vet[i] = -1;
}