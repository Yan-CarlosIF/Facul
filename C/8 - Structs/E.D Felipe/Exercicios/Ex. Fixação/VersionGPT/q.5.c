#include <stdio.h>
#include <stdlib.h>

// Multiplicação Escalar de Vetor com Liberação de Memória:

// Alocar dinamicamente um vetor de inteiros e preencher com valores fornecidos pelo usuário.
// Multiplique cada elemento do vetor por uma constante escalar, depois imprima o vetor resultante.
// Após o uso, libere a memória.

int main() {
    int size, escalar;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memoria.\n");
        return 1;
    }

    printf("Digite %d elementos para o vetor:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Digite o valor escalar para multiplicar cada elemento do vetor: ");
    scanf("%d", &escalar);

    printf("\nVetor apos a multiplicacao por %d: ", escalar);
    for (int i = 0; i < size; i++) {
        arr[i] *= escalar;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
