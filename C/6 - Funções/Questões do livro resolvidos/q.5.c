#include <stdio.h>

float percentual(float vAntigo, float vAtual);

int main()
{
    float valorAntigo, valorAtual;

    printf("Digite o valor antigo do produto:");
    scanf("%d", &valorAntigo);
    printf("Digite o valor atual do produto:");
    scanf("%d", &valorAtual);

    float resultado = percentual(valorAntigo, valorAtual);

    if (resultado >= 0)
    {
        printf("\nPercentual de acrescimo: %.2f%%", resultado);
    }
    else 
    {
        printf("\nPercentual de desconto: %.2f%%", resultado * -1);
    }

    return 0;
}

float percentual(float vAntigo, float vAtual)
{
    return ((vAtual - vAntigo) / vAntigo) * 100;
}