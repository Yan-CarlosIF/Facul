#include <stdio.h>

void uniaoVetores(int *vet1, int *vet2) {
  int vet3[20], tam = 0;

  for (int i = 0; i < 10; i++) {
    vet3[tam++] = vet1[i];
    vet3[tam++] = vet2[i];
  }

  for (int i = 0; i < tam; i++) {
    printf("%d ", vet3[i]);
  }
}

int main() {
  const int vet1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int vet2[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  uniaoVetores(vet1, vet2);
  return 0;
}