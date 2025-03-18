#include <stdio.h>

/*
Questão 6: Sequência de Fibonacci
Escreva uma função recursiva fibonacci(int n) que retorne o n-ésimo termo da sequência de Fibonacci. Lembre-se de que a sequência começa com 0 e 1, e cada termo seguinte é a soma dos dois anteriores.

Dica: A função deve ter casos base para n = 0 e n = 1, que retornam 0 e 1, respectivamente.
*/

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci (n - 2);
}

int main() {    
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}