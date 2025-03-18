/* 
Crie uma sub-rotina que receba três números inteiros como parâmetros, 
representando horas, minutos e segundos, e os converta em segundos. 

Exemplo: 2h, 40min e 10s correspondem a 9.610 segundos
*/

#include <stdio.h>

int transformaSegundos(int *h, int *m, int *s)
{
    return (*h*3600) + (*m*60) + *s;
}

int main()
{
    int horas, minutos, segundos;

    printf("Digite horas, minutos e segundos em ordem:");
    scanf("%d %d %d", &horas, &minutos, &segundos);

    int resultado = transformaSegundos(&horas, &minutos, &segundos);

    printf("\n%dh, %dmin e %ds = %d segundos", horas, minutos, segundos, resultado);
    return 0;
}