#include <stdio.h>
#include <stdlib.h>

// Crie um programa que declare um ponteiro para um ponteiro de inteiros. Atribua o endereço de um ponteiro
// para um valor inteiro e, por fim, altere o valor da variável original através do ponteiro para ponteiro.

int main() {
    int valor = 5;
    int *ponteiro = &valor;
    int **ponteiroP = &ponteiro;

    **ponteiroP *= 2;

    printf("Valor = %d", **ponteiroP);  
    return 0;
}