#include <stdio.h>

/*
Questão 3: Potência de um Número
Implemente uma função recursiva potencia(int base, int expoente) que calcule a potência de um número base elevado a um expoente inteiro positivo. 
Por exemplo, potencia(2, 3) deve retornar 8 (pois 2^3=8).

Dica: A potência de base com expoente 0 é 1. Caso contrário, multiplique a base pela chamada recursiva potencia(base, expoente - 1).
*/

int potencia(int num, int expo) {
    if (expo == 0) return 1;
    if (expo == 1) return num;
    return num * potencia(num, expo - 1);
}

int main() {
    printf("%d", potencia(2, 3));
    return 0;
}