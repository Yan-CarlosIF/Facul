// Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual,
// calcule e mostre: a) a idade dessa pessoa; b)  quantos anos ela terá em 2050.

#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *date = localtime(&t);

  int anoAtual = date->tm_year + 1900;
  int idadeAtual;

  printf("Qual sua idade: ");
  scanf("%d", &idadeAtual);

  printf("Voce tem %d anos\n", idadeAtual);
  
  printf("Você terá %d anos em 2050\n", idadeAtual + (2050 - anoAtual));

  return 0;
}