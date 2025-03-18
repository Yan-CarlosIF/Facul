// Faça um programa que preencha um vetor com dez números inteiros
// calcule e mostre o vetor resultante de uma ordenação decrescente.
#include <stdio.h>
#define tam 10

int main() {
    int vetor[tam];

    printf("Digite %d numeros inteiros:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < tam; i++) {
        for (int j = i; j < tam; j++) {
            if (vetor[i] < vetor[j]) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("\nOs numeros do vetor em ordem decrescente: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}