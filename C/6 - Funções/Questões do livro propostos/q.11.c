/*
Faça uma sub-rotina que receba como parâmetro um valor inteiro e positivo N,
indicando a quantidadede parcelas de uma soma S, calculada pela fórmula:

S = 2/4 + 5/5 + 10/6 + 17/7 + 26/8 + ... + (n^2 + 1)/(n + 3)
*/

#include <stdio.h>
#include <math.h>
float somaS(int N) {
    float S = 0;

    for (int i = 1; i <= N; i++) {
        S += (pow(i, 2) + 1)/(float)(i + 3);
    }

    return S;
}

int main() {
    int valor;

    do
    {
        printf("Digita ai:");
        scanf("%d", &valor);
    } while (valor < 0);

    printf("\nSoma de S = %.1f", somaS(valor));
    return 0;
}
