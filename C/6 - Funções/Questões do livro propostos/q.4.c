/* 
Faça uma sub-rotina que receba como parâmetro o raio de uma esfera, 
calcule e mostre no programa principal o seu volume: v = 4/3 * R3
*/

#include <stdio.h>
#include <math.h>

float volume(float raio)
{
    return (4/(float)3) * pow(raio, 3);
}

int main()
{
    float raio;

    printf("Digita o raio ai man:");
    scanf("%f", &raio);

    printf("\nVolume: %.2f", volume(raio));
    return 0;
}