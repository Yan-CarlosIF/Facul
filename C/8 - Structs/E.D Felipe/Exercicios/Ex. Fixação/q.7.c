#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que declare uma função que some dois números. 
// Em seguida, declare um ponteiro para essa função e use o ponteiro para chamar a função e imprimir o resultado.

void soma(int *a, int *b) {
    *a = *a + *b;
}

int main() {
    void (*pSoma)(int*, int*) = soma;
    int x = 1, y = 2;
    pSoma(&x , &y);
    
    printf("resultado = %d", x);
    return 0;
}