#include <stdbool.h>
#include <stdio.h>

// Dois números são considerados AMIGÁVEIS se um deles corresponder à soma dos
// divisores (exceto o
//     próprio número) do outro.
//     Por exemplo: vamos analisar os números 8 e 10.
//     Os divisores de 8 são: 1, 2 e 4, resultando em soma igual a 7.
//     Já os divisores de 10 são: 1, 2 e 5, resultando em soma igual a 8.
//     Assim, como a soma dos divisores de 10 (exceto ele próprio) resulta em 8,
//     pode-se dizer que os números 10 e 8 são amigáveis.

// Criar um programa que receba dois números inteiros quaisquer e determine se
// são amigáveis ou não.
int main() {
  int numero1, numero2;

  printf("Digite o primeiro numero: ");
  scanf("%d", &numero1);

  printf("Digite o segundo numero: ");
  scanf("%d", &numero2);

  int somaDivisores1 = 0;
  int somaDivisores2 = 0;

  for (int i = 1; i < numero1; i++)
    if (numero1 % i == 0) somaDivisores1 += i;

  if (somaDivisores1 == numero2) {
    printf("\nOs numeros %d eh %d sao amigaveis!\n", numero1, numero2);
    return 0;
  }

  for (int i = 1; i < numero2; i++)
    if (numero2 % i == 0) somaDivisores2 += i;

  if (somaDivisores2 == numero1) {
    printf("\nOs numeros %d e %d sao amigaveis!\n", numero1, numero2);
  } else {
    printf("\nOs numeros %d e %d nao sao amigaveis...\n", numero1, numero2);
  }

  return 0;
}
