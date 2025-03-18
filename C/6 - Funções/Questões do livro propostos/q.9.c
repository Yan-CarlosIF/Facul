/* 
Crie uma sub-rotina que receba como parâmetro um valor 
inteiro e positivo e retorne a soma dos divisores desse valor.
*/

#include <stdio.h>

int somaDivisores(int num) {
    int soma = 0;
    
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            soma += i;
        }
    }

    return soma;
}

int main() {
    int num;

    do {
        printf("Digite um numero:");
        scanf("%d", &num);
    } while (num < 0);

    printf("soma dos divisores de %d: %d", num, somaDivisores(num));
    return 0;
}