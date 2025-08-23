// Faça um programa que receba uma frase e mostre as letras que se repetem,
// junto com o número de repetições.
// Exemplo: A PROVA FOI ADIADA
// ■ A letra A apareceu 5 vezes.
// ■ A letra O apareceu 2 vezes.
// ■ A letra I apareceu 2 vezes.
// ■ A letra D apareceu 2 vezes.
// Solução:
// ■■Digitar uma frase.
// ■■Pegar o tamanho da frase digitada.
// ■■Percorrer a frase, pegando caractere por caractere.
// ■■Verificar se é a primeira vez que esse caractere aparece na frase.
// ■■Caso seja a primeira vez, atribuir um ao contador de aparições.
// ■■Caso contrário, incrementar o contador de aparições em uma unidade.
// ■■Mostrar todas as letras que apareceram mais de uma vez (que se repetiram),
// junto com o total de repetições
#include <ctype.h>
#include <stdio.h>

int main() {
  char frase[100];
  int hashMap[26] = {0};

  printf("Digite uma frase: ");
  fgets(frase, 100, stdin);

  for (int i = 0; frase[i] != '\0'; i++) {
    if (frase[i] >= 97 && frase[i] <= 122) {
      frase[i] -= 32;
    }

    hashMap[frase[i] - 65]++;
  }

  for (int i = 0; i < 26; i++) {
    if (hashMap[i] > 1) {
      printf("A letra %c apareceu %d vezes\n", i + 65, hashMap[i]);
    }
  }

  return 0;
}