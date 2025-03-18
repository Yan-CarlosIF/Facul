/*
Faça uma sub-rotina que receba um valor inteiro e verifique se ele é positivo ou negativo.
*/

#include <stdio.h>
#include <stdbool.h>

bool negOuPosi(float num) {
    if (num < 0) return false;
    else return true;
}

int main()
{
    float num;

    printf("digita ai:");
    scanf("%f", &num);

    if (negOuPosi(num)) {
        printf("\nPositivo");
    } else {
        printf("\nNegativo");
    } 
    return 0;
}
