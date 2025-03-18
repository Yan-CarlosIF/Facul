#include <stdlib.h>
#include <stdio.h>

float sequencia(int num)
{
    float s = 1;
    for (float i = 2; i <= num; i++)
    {
        s += 1/i;
    }

    return s;
}
int main()
{
    int num;
    do {
        printf("Digite um numero: ");
        scanf("%d", &num);
    } while (num < 1);

    float resultado = sequencia(num);

    printf("\nResultado = %f", resultado);
    return 0;
}
