#include <stdio.h>

void maiorMenor(int *vet, int *maior, int *menor, int tam) {
    *maior = vet[0], *menor = vet[0];

    for (int i = 0; i < tam; i++) {
        if (*maior < vet[i]) {
            *maior = vet[i];
        }
        if (*menor > vet[i]) {
            *menor = vet[i];
        }
    }
}

int main() {
    int n;

    printf("Digite a quant de numeros:");
    scanf("%d", &n);

    int vetor[n], maior, menor;

    for (int i = 0; i < n; i++) {
        scanf("%d" , &vetor[i]);
    }

    maiorMenor(vetor, &maior, &menor, n);

    printf("maior = %d\nmenor = %d", maior, menor);
}