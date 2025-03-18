#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

int somaEntreOsNumeros(int n1, int n2);
void recebeVetor(int *vet1, int *vet2);
void uniaoEntreVetores(int *vet1, int *vet2);
int ValorDaPosicao(int *vet, const int i);
float operacoesAritmeticas(int n1, int n2, const char sinal);
void pesquisaCidade(float *mediaSalarios, float *mediaFilhos, int *contPessoas);

int main() {
  printf("Soma de todos os numeros: %d\n", somaEntreOsNumeros(1, 3));

  int vet1[SIZE], vet2[SIZE];
  recebeVetor(vet1, vet2);
  uniaoEntreVetores(vet1, vet2);
  printf("\nPosicao: %d", ValorDaPosicao(vet1, 1));
  printf("\nresultado: %.2f", operacoesAritmeticas(1, 2, '/'));

  float mediaSalarios = 0, mediaNumFilhos = 0;
  int contPessoasSalario = 0;
  pesquisaCidade(&mediaSalarios, &mediaNumFilhos, &contPessoasSalario);

  printf("Media de salarios: %.2f\n", mediaSalarios);
  printf("Media do numero de filhos: %.2f\n", mediaNumFilhos);
  printf("Quantidade de pessoas com salario menor que 380: %d\n",contPessoasSalario);

  return 0;
}

int somaEntreOsNumeros(int n1, int n2) {
  if (n1 > n2) {
    int aux = n1;
    n1 = n2;
    n2 = aux;
  }

  int soma = 0;

  for (int i = n1 + 1; i < n2; i++) {
    soma += i;
  }

  return soma;
}

void recebeVetor(int *vet1, int *vet2) {
  printf("\nPreencha o primeiro vetor:\n");
  for (int i = 0; i < SIZE; i++) {
    scanf("%d", &vet1[i]);
  }

  printf("\nPreencha o segundo vetor:\n");
  for (int i = 0; i < SIZE; i++) {
    scanf("%d", &vet2[i]);
  }
}

void uniaoEntreVetores(int *vet1, int *vet2) {
  int uniao[SIZE * 2], tam = 0;

  for (int i = 0; i < SIZE; i++) {
    int possui = 0;
    for (int j = 0; j < tam; j++) {
      if (uniao[j] == vet1[i]) {
        possui = 1;
        break;
      }
    }

    if (!possui) uniao[tam++] = vet1[i];

    possui = 0;
    for (int j = 0; j < tam; j++) {
      if (uniao[j] == vet2[i]) {
        possui = 1;
        break;
      }
    }

    if (!possui) uniao[tam++] = vet2[i];
  }

  printf("\nUniao entre os vetores: ");
  for (int i = 0; i < tam; i++) {
    printf("%d ", uniao[i]);
  }
}

int ValorDaPosicao(int *vet, const int i) {
  if (i < 0 || i >= SIZE) return -1;

  return vet[i];
}

float operacoesAritmeticas(int n1, int n2, const char sinal) {
  if (sinal != '*' && sinal != '/' && sinal != '+' && sinal != '-') return -1;

  switch (sinal) {
    case '+':
      return (float)n1 + n2;
      break;
    case '-':
      return (float)n1 - n2;
      break;
    case '*':
      return (float)n1 * n2;
      break;
    case '/':
      if (n2 != 0) {
        return n1 / (float)n2;
      } else {
        printf("\nNao eh possivel fazer divisao por zero!");
        return -1;
      }
      break;
    default:
      printf("sinal inválido!");
      return -1;
      break;
  }
}

void pesquisaCidade(float *mediaSalarios, float *mediaFilhos, int *contPessoas) {
  int quantidadePessoas;
  printf("\nInsira a quantidade de pessoas entrevistadas: ");
  scanf("%d", &quantidadePessoas);

  float *salarios = (float *)malloc(sizeof(float) * quantidadePessoas);
  int *filhos = (int *)malloc(sizeof(int) * quantidadePessoas);

  for (int i = 0; i < quantidadePessoas; i++) {
    printf("preencha o salario da %d pessoa entrevistada: ", i + 1);
    scanf("%f", &salarios[i]);
    *mediaSalarios += salarios[i];

    printf("\nA quantidade de filhos da %d pessoa entrevistada: ", i + 1);
    scanf("%d", &filhos[i]);
    *mediaFilhos += filhos[i];

    if (salarios[i] < 380) (*contPessoas)++;
  }

  *mediaSalarios /= quantidadePessoas;
  *mediaFilhos /= quantidadePessoas;
}