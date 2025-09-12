#include <ctype.h>
#include <stdio.h>

int main() {
  char str[100], palavra[100];
  int cont = 0;

  printf("Insira uma frase: ");
  fgets(str, 100, stdin);

  printf("Insira uma palavra: ");
  fgets(palavra, 100, stdin);

  for (int i = 0; str[i] != '\0'; i++) {
    int eigual = 1;
    for (int j = 0; palavra[j] != '\0'; j++) {
      char c = tolower(palavra[j]), c2 = tolower(str[i + j]);

      if (c != c2) {
        eigual = 0;
        break;
      }
    }
    if (eigual == 1) {
      cont++;
    }
  }

  printf("\n%d\n", cont);
  return 0;
}