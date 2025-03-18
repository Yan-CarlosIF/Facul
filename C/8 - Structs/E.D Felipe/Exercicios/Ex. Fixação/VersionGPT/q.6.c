#include <stdio.h>
#include <stdlib.h>

// Ponteiro para Função com Operação Diferente:

// Escreva uma função que multiplique dois números inteiros e retorne o resultado.
// Crie um ponteiro para essa função e use-o para calcular e imprimir o produto de dois valores fornecidos pelo usuário.

int mult(int x, int y) {
    return x * y;
}

int main() {
    int (*pMult)(int, int) = mult;

    int resultado = pMult(3, 4);

    printf("\nResultado = %d", resultado);
    return 0;
}