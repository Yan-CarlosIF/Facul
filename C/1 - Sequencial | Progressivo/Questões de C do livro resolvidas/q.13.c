// pé = 12 polegadas 
// 1 jarda = 3 pés
// 1 milha = 1,760 jarda
// Faça um programa que receba uma medida em pés, faça as conversões a seguir e mostre os resultados.
// a) polegadas; 
// b) jardas; 
// c) milhas.

#include <stdio.h>

int main() {
    float pes;

    printf("Insira uma medida em pes: ");
    scanf("%f", &pes);

    float polegadas = pes * 12;
    float jardas = pes / 3;
    float milhas = jardas * 1760;

    printf("Polegadas: %.2f\n", polegadas);
    printf("Jardas: %.2f\n", jardas);
    printf("milhas: %.2f\n", milhas);

    return 0;
}