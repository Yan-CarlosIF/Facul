#include <stdio.h>
#include <stdlib.h>

/*
Problema 1: Você deve ler uma quantidade desconhecida de números positivos informadas pelo usuário que, 
ao terminar, digitará o número -1, sem falha. Armazene estes números em memória e ao final os exiba no terminal.
*/

int main() {
    int *vetNumeros;
    int cont = 0, capacidade = 5, numero;
    vetNumeros = (int*)malloc(sizeof(int) * capacidade);

    printf("Digite numeros positivos ou -1 para terminar:\n");
    do {
        scanf("%d", &numero);

        if (numero >= 0) {
            if (cont == capacidade) {
                capacidade *= 2;
                vetNumeros = (int*)realloc(vetNumeros, sizeof(int) * capacidade);
            }

            vetNumeros[cont++] = numero;
        }
    } while (numero != -1);


    printf("\nNumeros:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d ", vetNumeros[i]);
    }

    
    // Problema 2: A partir do problema 1, você deve ordenar os valores em ordem crescente
    printf("\nNumeros na ordem crescente:\n");
    for (int i = 0; i < cont; i++) {
        for (int j = i; j < cont; j++) {
            if (vetNumeros[i] > vetNumeros[j]) {
                int aux = vetNumeros[i];
                vetNumeros[i] = vetNumeros[j];
                vetNumeros[j] = aux;
            }
        }
        printf("%d ", vetNumeros[i]);
    }
    
    free(vetNumeros);
    return 0;
}