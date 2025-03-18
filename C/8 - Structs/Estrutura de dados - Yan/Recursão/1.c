#include <stdio.h>

/*
Questão 1: Soma dos Números de 1 até N
Escreva uma função recursiva somaN(int n) que receba um número inteiro positivo n e retorne a soma de todos os números de 1 até n. 
Por exemplo, somaN(5) deve retornar 15 (pois 1 + 2 + 3 + 4 + 5 = 15).

Dica: A função deve ter um caso base para n = 1, onde o resultado é 1.
*/

int somaN(int *arr, const int tam) {
    if (tam <= 0) return 0;
    return arr[0] + somaN(arr + 1, tam - 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int tam = sizeof(arr) / sizeof(arr[0]);

    int result = somaN(arr, tam);
    
    printf("Resultado = %d", result);
    
    return 0;
}