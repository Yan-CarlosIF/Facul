#include <stdio.h>
#include <string.h>
// Um problema típico em ciência da computação consiste em converter um número
// da sua forma decimal para a forma binária. Por exemplo, o número 12 tem sua
// representação binária igual a 1.100. A forma mais simples de fazer isso é
// dividir o número sucessivamente por 2, cujo resto da i-ésima divisão vai ser
// o dígito i do número binário (da direita para a esquerda).

// Por exemplo: 12 / 2 = 6, resto 0 (1o dígito da direita para esquerda), 6 / 2
// = 3, resto 0 (2o dígito da direita para esquerda), 3 / 2 = 1 resto 1 (3o
// dígito da direita para esquerda), 1 / 2 = 0 resto 1 (4o dígito da direita
// para esquerda). Resultado: 12 = 1100.

int main() {
  int num, i = 0;
  printf("Digite um numero: ");
  scanf("%d", &num);
  char bin[100] = "";

  // Forma de fazer usando potencia de 10
  //   float bin = 0;
  //   int i = 0;
  //   while (num > 0) {
  //     bin += (num % 2) * pow(10, i);
  //     num /= 2;
  //     i++;
  //   }
  //   printf("%.f", bin);

  while (num > 0) {
    bin[i++] = num % 2 + '0';
    num /= 2;
  }

  int size = strlen(bin);
  for (int i = 0; i < size / 2; i++) {
    char aux = bin[i];
    bin[i] = bin[size - i - 1];
    bin[size - i - 1] = aux;
  }

  printf("\nForma binaria: %s", bin);
  return 0;
}