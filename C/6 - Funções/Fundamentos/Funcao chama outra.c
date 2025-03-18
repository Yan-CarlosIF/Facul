#include <stdio.h>

float valorAbsoluto(float n)
{
    return n * -1;
}

float somaDigitos(float n1, float n2)
{
    if (n1 < 0)
    {
        n1 = valorAbsoluto(n1);
    }

    if (n2 < 0)
    {
        n2 = valorAbsoluto(n2);
    }

    return n1 + n2;
}

int main()
{
    float n1, n2;
    printf("Digite um numero:");
    scanf("%f", &n1);

    printf("Digite um numero:");
    scanf("%f", &n2);

    float resultado = somaDigitos(n1, n2);

    printf("\nSoma digitos: %d", resultado);
    return 0;
}
