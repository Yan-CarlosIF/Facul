#include <stdio.h>

// Questão 8: Contagem de Ocorrências em um Array
// Escreva uma função recursiva contaOcorrencias(int array[], int tamanho, int valor) que conte quantas vezes um determinado valor aparece em um array de inteiros. A função deve retornar o número de ocorrências do valor no array.

// Dica: Compare o primeiro elemento do array com o valor e adicione 1 à contagem se houver correspondência.

int contaOcorrencias(int *arr, int tam, int valor) {
    if (tam == 0) {
        return 0;
    }

    int contaAtual = (arr[0] == valor) ? 1 : 0;

    return contaAtual + contaOcorrencias(arr + 1, tam - 1, valor);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5, 6};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n%d\n", contaOcorrencias(arr, tam, 5), contaOcorrencias(arr, tam, 6));
    return 0;
}