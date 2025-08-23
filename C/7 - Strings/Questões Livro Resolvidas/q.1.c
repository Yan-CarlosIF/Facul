// Faça um programa que receba uma frase, calcule e mostre a quantidade de
// vogais da frase digitada. O programa deverá contar vogais maiúsculas e
// minúsculas. Solução: ■■Digitar uma frase. ■■Pegar o tamanho da frase.
// ■■Percorrer a frase, pegando caractere por caractere.
// ■■Comparar cada caractere com as vogais (maiúsculas e minúsculas).
// ■■Quando encontrar uma vogal, acrescentar um na quantidade.

#include <stdio.h>

int contarVogais(char *frase) {
  int cont = 0;

  for (int i = 0; frase[i] != '\0'; i++) {
    if (frase[i] == 'A' || frase[i] == 'a' || frase[i] == 'E' ||
        frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'I' ||
        frase[i] == 'o' || frase[i] == 'O' || frase[i] == 'u' ||
        frase[i] == 'U') {
      cont++;
    }
  }

  return cont;
}

int main() {
  char frase[100];

  printf("Insira uma frase: ");
  fgets(frase, 100, stdin);

  printf("Quantidade de vogais na frase: %d\n", contarVogais(frase));

  return 0;
}
