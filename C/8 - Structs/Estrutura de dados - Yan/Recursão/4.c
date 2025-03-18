#include <stdio.h>

// Questão 4: Soma dos Dígitos de um Número
// Escreva uma função recursiva somaDigitos(int numero) que receba um número inteiro positivo e retorne a soma de seus dígitos. Por exemplo, somaDigitos(1234) deve retornar 10 (pois 1 + 2 + 3 + 4 = 10).

// Dica: Use o operador módulo (%) para obter o último dígito e a divisão inteira (/) para reduzir o número.

int somaDigitos(int num) {
    if (num == 0) {
        return 0;
    }

    return (num % 10) + somaDigitos(num / 10);
}

int main() {
    printf("%d", somaDigitos(12345));
    return 0;
}