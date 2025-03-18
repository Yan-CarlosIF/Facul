#include <stdio.h>
#include <stdlib.h>

// Alocação Dinâmica e Soma de Elementos:

// Use malloc() para alocar um vetor de inteiros cujo tamanho será dado pelo usuário.
// Solicite ao usuário para preencher o vetor e, em seguida, some todos os elementos.
// Imprima o valor total da soma e libere a memória.

int main() {
    int tam, soma = 0;

    printf("Digite o tamanho desejado para o array:");
    scanf("%d", &tam);

    int *arr = (int *)malloc(sizeof(int) * tam);
    
    printf("\nDigite %d numeros:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
        soma += arr[i];
    }

    printf("\nResutado da Soma = %d\n", soma);

    free(arr);
    return 0;
}