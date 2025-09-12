/*
Faça um programa para criptografar uma frase em que cada caractere deverá ser
substituído pelo caractere que está três posições à sua frente na tabela ASCII.
Os três últimos caracteres da tabela ASCII
deverão ser substituídos pelos três primeiros.
Exemplo:
BONECO ZABUMBA
ERQHFR CDEXPED
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char str[100] = "BONECO ZABUMBA";

  int tam = strlen(str);
  for (int i = 0; i < tam; i++) {
    if (str[i] >= 'x' && str[i] <= 'z') {
      str[i] = str[i] - 23;
    } else if (str[i] >= 'X' && str[i] <= 'Z') {
      str[i] = str[i] - 23;
    } else {
      if (isalpha(str[i])) {
        str[i] += 3;
      }
    }
  }

  printf("%s\n", str);

  return 0;
}