#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Escreva um programa que declare e atribua um valor a uma variável inteira e, em seguida, declare um ponteiro para essa variável. 
// Imprima os valores antes. Use o ponteiro para alterar o valor da variável e exiba o valor depois da alteração a partir da variável original. 
// Você talvez queira utilizar funções que recebem argumentos por referência.

void funcMudaValor(int *valor) {
    srand(time(NULL));
    int numeroAleatorio = rand() % 10 + 1;
    printf("\n%d * %d\n", *valor, numeroAleatorio);
    *valor *= numeroAleatorio;
}

int main() {
    int x;

    printf("Digite um valor: ");
    scanf("%d", &x);

    printf("\nValor antes da funcao: %d\n", x);
    int *ponteiro = &x;

    funcMudaValor(ponteiro);

    printf("\nValor depois da funcao: %d\n", *ponteiro);
    return 0;
}