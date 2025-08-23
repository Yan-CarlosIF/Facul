// Faça um programa que receba um número positivo e maior que zero, calcule e mostre: 
// a) o número digitado ao quadrado; 
// b)  o número digitado ao cubo; 
// c) a raiz quadrada do número digitado; 
// d)  a raiz cúbica do número digitado.

#include <stdio.h>
#include <math.h>

int main() {
    float number; 

    do {
        printf("Insira um numero: ");
        scanf("%f", &number);
    } while (number <= 0);

    printf("\nAo quadrado: %.2f", pow(number, 2));
    printf("\nAo cubo: %.2f", pow(number, 3));
    printf("\nraiz quadrada: %.2f", sqrt(number));
    printf("\nraiz cubica: %.2f", cbrt(number));
    
    return 0;
}