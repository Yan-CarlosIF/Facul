#include <stdio.h>

float calculadora(float n1, float n2, char sim)
{
    if (sim == '+')
    {
        return n1 + n2;
    }
    else
    {
        return n1 * n2;
    }
}

int main()
{
    float n1, n2;
    char simbolo;
    printf("Digite dois numeros:");
    scanf("%f %f", &n1, &n2);

    do {
        printf("Digite '+' para adicao\nDigite '*' para Multiplicacao:\n");
        fflush(stdin);
        scanf("%c", &simbolo);
    } while (simbolo != '+' && simbolo != '*');

    float resultado = calculadora(n1, n2, simbolo);

    printf("\nResultado = %.1f\n", resultado);
    return 0;
}
