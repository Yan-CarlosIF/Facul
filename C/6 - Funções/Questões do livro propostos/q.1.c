/* Faça uma sub-rotina que receba um número inteiro e positivo N como parâmetro e 
retorne a soma dos números inteiros existentes entre o número 1 e N (inclusive). */

#include <stdio.h>

int soma(int *n)
{
    int soma = 0;
    for (int i = 1; i <= *n; i++)
    {
        soma += i;
    }

    return soma;
}

int main()
{
    int N;

    printf("Digite um numero:");
    scanf("%d", &N);

    int resultado = soma(&N);

    printf("\nResultado da soma = %d", resultado);
    return 0;
}