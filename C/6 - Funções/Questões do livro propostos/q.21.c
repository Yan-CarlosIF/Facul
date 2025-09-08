#include <stdio.h>

int somaPrimos(const int x, const int y) {
  int soma = 0;

  for (int i = x; i <= y; i++) {
    int cont = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        cont++;
      }
    }

    if (cont == 2) {
      soma += i;
    }
  }

  return soma;
}

int main() {
  int x, y;

  do {
    do {
      printf("Insira o valor de x e y:");
      scanf("%d %d", &x, &y);

      if (x > y) {
        printf("O valor de x deve ser maior que o valor de y!\n");
      }
    } while (x > y);

    if (x != y) {
      printf("X: %d, Y: %d\nSoma dos primos entres eles: %d\n", x, y,
             somaPrimos(x, y));
    }
  } while (x != y);

  return 0;
}