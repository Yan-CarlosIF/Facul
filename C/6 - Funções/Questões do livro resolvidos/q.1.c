#include <stdio.h>

int posiOuNeg(int num)
{
    return num >= 0 ? 1 : 0;
}

int main()
{
    int numero;

    printf("Digite um numero:");
    scanf("%d", &numero);

    if (posiOuNeg(numero))
    {
        printf("\nEh positivo!");
    }
    else 
    {
        printf("\nEh negativo!");
    }

    return 0;
}
