#include <stdio.h>
#include <stdlib.h>
#define FUNCS 2

// Faça um programa que carregue três vetores nos quais serão armazenados os
// códigos, os salários e o tempo do serviço, em anos, de cinco funcionários.
// Posteriormente, o programa deverá:

// c) Gerar e mostrar um quarto vetor com os códigos dos funcionários que
// possuem tempo de serviço entre 2 e 4 anos e são isentos de impostos. Sabe-se
// que os funcionários isentos de impostos são aqueles que possuem salário
// inferior a R$ 1.500,00. Caso nenhum funcionário preencha os requisitos,
// mostrar mensagem.

void menorSalario(float funcs[][3]);
void exibirSalarios(float funcs[][3], float salarioComparacao);

int main() {
  float funcionarios[FUNCS][3];

  printf("Insira os dados dos funcionarios: \n");
  for (int i = 0; i < FUNCS; i++) {
    printf("\nDigite o codigo do %d funcionario: ", i + 1);
    scanf("%f", &funcionarios[i][0]);
    printf("\nDigite o salario do %d funcionario: ", i + 1);
    scanf("%f", &funcionarios[i][1]);
    printf("\nDigite o tempo de servico do %d funcionario (em anos): ", i + 1);
    scanf("%f", &funcionarios[i][2]);
  }

  float salarioComparacao;
  printf("\nDigite o salario a ser consultado: ");
  scanf("%f", &salarioComparacao);

  exibirSalarios(funcionarios, salarioComparacao);

  menorSalario(funcionarios);

  int cont = 0;
  float codigos[FUNCS];

  for (int i = 0; i < FUNCS; i++) {
    if (funcionarios[i][2] >= 2 && funcionarios[i][2] <= 4) {
      codigos[cont++] = funcionarios[i][0];
    }
  }

  printf("\nCodigos dos funcionarios com tempo de servico entre 2 e 4 anos: ");
  for (int i = 0; i < cont; i++) printf("%.f, ", codigos[i]);
  return 0;
}

// a) Receber um valor que corresponde ao salário a ser consultado e, em
// seguida, mostrar dois relatórios. Cada relatório deverá mostrar o código do
// funcionário e o salário. O primeiro relatório deve mostrar os funcionários
// que têm salário até o valor digitado e o segundo relatório deve mostrar os
// funcionários que possuem salário superior ao valor digitado. Caso não exista
// nenhum funcionário em algum dos relatórios, mostrar mensagem.
void exibirSalarios(float funcs[][3], float salarioComparacao) {
  printf("\nSalarios ate %.2fR$: \n", salarioComparacao);
  for (int i = 0; i < FUNCS; i++) {
    if (funcs[i][1] <= salarioComparacao) {
      printf("Codigo: %.f - Salario: %.2fR$", funcs[i][0], funcs[i][1]);
    }
  }

  printf("\n\nSalarios Superiores a %.2fR$: \n", salarioComparacao);
  for (int i = 0; i < FUNCS; i++) {
    if (funcs[i][1] > salarioComparacao) {
      printf("Codigo: %.f - Salario: %.2fR$", funcs[i][0], funcs[i][1]);
    }
  }
}

// b) Encontrar o menor salário pago, calcular e mostrar quantos funcionários
// têm salário igual ao menor salário e, posteriormente, mostrar os códigos
// desses funcionários.
void menorSalario(float funcs[][3]) {
  float menor = funcs[0][1], codigos[FUNCS];
  int cont = 0;

  for (int i = 0; i < FUNCS; i++)
    if (menor > funcs[0][1]) menor = funcs[0][1];

  for (int i = 0; i < FUNCS; i++) {
    if (funcs[i][1] == menor) {
      codigos[cont++] = funcs[i][0];
    }
  }

  if (cont > 1) {
    printf("\n\nCodigos dos funcionarios com o salario igual ao menor salario: ");
    for (int i = 0; i < cont; i++) printf("%.f, ", codigos[i]);
  } else {
    printf("\nNenhum funcionario tem o codigo igual o do menor\n");
  }
}
