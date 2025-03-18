/*
Elabore uma sub-rotina que leia um número não determinado de valores positivos
e retorne a média aritmética desses valores. Terminar a entrada de dados com o valor zero
*/

#include <stdio.h>

float mediaAritmetica() {
    float soma = 0, nums;
    int cont = 0;

    do {
        printf("Digite um numero:");
        scanf("%f", &nums);

        if (nums > 0) {
            soma += nums;
            cont++;
        }
    } while (nums != 0);

    return soma/(float)cont;
}

int main() {
    float result = mediaAritmetica();

    printf("\nMedia dos numeros digitados: %.2f", result);
    return 0;
}
