// Faça um programa que receba três notas e seus respectivos pesos, calcule e mostre a média ponderada.

#include <stdio.h>
#include <math.h>

int main() {
    float notas[3];
    float pesos[3];
    float somaPesos = 0;

    for (int i = 0; i < 3; i++) {
        printf("Insira a %d nota: ", i + 1);
        scanf("%f", &notas[i]);

        printf("Insira o %d peso: ", i + 1);
        scanf("%f", &pesos[i]);

        somaPesos += pesos[i];
    }
    
    float media_ponderada = ((notas[0] * pesos[0]) + (notas[1] * pesos[1]) + (notas[2] * pesos[2])) /  somaPesos;

    printf("Media ponderada: %.2f", media_ponderada);
    
    return 0;
}