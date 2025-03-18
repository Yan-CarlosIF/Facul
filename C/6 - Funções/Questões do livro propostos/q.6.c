/*
Crie uma sub-rotina que receba como parâmetro a altura (alt) e o sexo de uma pessoa e retorne seu peso ideal.
Para homens, deverá calcular o peso ideal usando a fórmula: peso ideal = 72.7 *alt − 58; para mulheres: peso
ideal = 62.1 *alt − 44.7
*/

#include <stdio.h>
#include <ctype.h>

float pesoIdeal(float altura, char sexo) {
    if (tolower(sexo) == 'm') {
        return (72.7 * altura) - 58;
    } else {
        return (62.1 * altura) - 44.7;
    }
}

int main() {
    float altura;
    char sexo;

    printf("Digite sua altura:");
    scanf("%f", &altura);

    do {
        printf("Digite o sexo:");
        fflush(stdin);
        scanf("%c", &sexo);
    } while (tolower(sexo) != 'm' && tolower(sexo) != 'f');

    float pesoI = pesoIdeal(altura, sexo);

    if (tolower(sexo) == 'f') {
        printf("\nPeso ideal para uma mulher com %.2f de altura eh: %.2f\n", altura, pesoI);
    } else {
        printf("\nPeso ideal para um homem com %.2f de altura eh: %.2f\n", altura, pesoI);
    }

    return 0;
}
