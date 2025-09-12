/*
Faça um programa que receba uma frase e troque a palavra ALUNO por ESTUDANTE e a
palavra ESCOLA por UNIVERSIDADE. Exemplo: EU SOU ALUNO DA ESCOLA Saída: EU SOU
ESTUDANTE DA UNIVERSIDADE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trocaPalavras(char *frase) {
  char *fraseTrocada = (char *)malloc(200), *palavra;
  fraseTrocada[0] = '\0';
  palavra = strtok(frase, " \n");

  while (palavra != NULL) {
    if (strcasecmp(palavra, "aluno") == 0) {
      strcat(fraseTrocada, "ESTUDANTE");
    } else if (strcasecmp(palavra, "escola") == 0) {
      strcat(fraseTrocada, "UNIVERSIDADE");
    } else {
      strcat(fraseTrocada, palavra);
    }

    strcat(fraseTrocada, " ");
    palavra = strtok(NULL, " \n");
  }

  int fraseSize = strlen(fraseTrocada);
  if (fraseSize > 0) {
    fraseTrocada[fraseSize - 1] = '\0';
  }

  return fraseTrocada;
}

int main() {
  char frase[100], *fraseTrocada;

  printf("Digite uma frase:");
  fgets(frase, 100, stdin);

  fraseTrocada = trocaPalavras(frase);

  printf("\nFrase: %s", fraseTrocada);

  free(fraseTrocada);
  return 0;
}
