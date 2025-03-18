#include <stdio.h>
#include <stdlib.h>

// Modificação de Valor através de Ponteiro:

// Declare duas variáveis inteiras com valores diferentes.
// Crie um ponteiro que inicialmente aponte para a primeira variável e imprima seu valor.
// Altere o ponteiro para apontar para a segunda variável e modifique o valor dela por meio do ponteiro.
// Imprima os valores finais das duas variáveis.

int main() {
    int x = 5, y = 2;
    int *ponteiroX = &x;

    printf("\nValor da variavel x = %d", *ponteiroX);

    ponteiroX = &y;
    *ponteiroX *= 2;

    printf("\nValor Final de x = %d\nValor final de y = %d", x, *ponteiroX);
    return 0;
}