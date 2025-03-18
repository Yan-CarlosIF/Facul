#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alguns números inteiros possuem a capacidade de se autoelogiarem através de seus dígitos. Estes são 
// números  que  formam  a  família  dos  Números  Narcisistas.  Os  Números  Narcisistas  clássicos  são  aqueles  
// iguais à soma de cada um de seus dígitos elevados à potência do número total de dígitos.
// Por exemplo, o número 153 é um narcisista clássico porque a soma de cada um de seus dígitos elevados 
// ao cubo (total de dígitos que compõem o número 153) é exatamente 153.

//                  153 = 13 + 53 + 33 = 1 + 125 + 27 = 153

// Crie um programa que receba um número qualquer e determine se ele é Narcisista ou não.
int main() {
  int numero;

  printf("Digite um numero: ");
  scanf("%d", &numero);

  char *numeroString = (char *)malloc(sizeof(char) * 100);
  itoa(numero, numeroString, 10);
  int size = strlen(numeroString);
  float numeroNarcisista = 0;

  for (int i = 0; i < size; i++) {
    int digito = numeroString[i] - '0';
    float potencia = pow(digito, size);
    numeroNarcisista += potencia;
  }

  if (numeroNarcisista == numero) {
    printf("\nO numero %d eh narcisista.\n", numero);
  } else {
    printf("\nO numero %d nao eh narcisista.\n", numero);
  }

  return 0;
}