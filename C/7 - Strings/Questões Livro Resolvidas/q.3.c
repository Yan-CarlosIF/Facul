/* Faça um programa que receba uma frase, calcule e mostre a quantidade de
 * palavras da frase digitada. */
#include <stdio.h>
#include <string.h>

int len(char *frase) {
  int cont = 0;

  for (int i = 0; frase[i] != '\0'; i++) cont++;

  return cont;
}

void trim(char *frase) {
  int inicio = 0;
  int fim = strlen(frase) - 1;

  while (frase[inicio] == ' ' || frase[inicio] == '\n') {
    inicio++;
  }

  while (fim >= inicio &&
         (frase[fim] == ' ' || frase[fim] == '\0' || frase[fim] == '\n')) {
    fim--;
  }

  int j = 0;
  for (int i = inicio; i <= fim; i++) {
    frase[j++] = frase[i];
  }

  frase[j] = '\0';
}

int contPalavras(char *frase) {
  int cont = 0;
  char *palavra, fraseCopia[50];
  strcpy(fraseCopia, frase);
  palavra = strtok(fraseCopia, " ");

  while (palavra != NULL) {
    cont++;
    palavra = strtok(NULL, " ");
  }

  return cont;
}

int contPalavras2(char *frase) {
  int cont = 0;

  trim(frase);

  for (int i = 0; frase[i] != '\0'; i++) {
    if (i != 0 && frase[i] == ' ') {
      cont++;
    }
  }

  return cont + 1;
}

int main() {
  char frase[50];

  printf("Digite uma frase:");
  fgets(frase, 50, stdin);

  trim(frase);

  int cont = contPalavras(frase);
  int cont2 = contPalavras2(frase);

  printf("\nQuantidade de palavras da frase '%s': %d\n", frase, cont);
  printf("Quantidade de palavras da frase '%s' (sem strtok): %d\n", frase, cont2);
  return 0;
}
