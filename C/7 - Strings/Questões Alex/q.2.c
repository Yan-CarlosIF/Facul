#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int len(char *str) {
  int cont = 0;
  for (int i = 0; str[i] != '\0'; i++) cont++;
  return cont;
}

int isPalindrome(char *str) {
  int length = len(str);
  char invertedString[20];
  strcpy(invertedString, str);

  for (int i = 0; i < length / 2; i++) {
    char aux = invertedString[i];
    invertedString[i] = invertedString[length - i - 1];
    invertedString[length - i - 1] = aux;
  }

  return stricmp(str, invertedString) == 0;
}

int main() {
  char str[20];

  printf("Insira uma palavra: ");
  fgets(str, sizeof(20), stdin);

  printf("\n%s\n", isPalindrome(str) ? "é palindromo" : "não é palindromo");
}