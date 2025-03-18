/*
Faça um programa que receba uma frase e mostre cada palavra dela em uma linha separada.
Exemplo:
Frase: COMPUTADORES SÃO MÁQUINAS POTENTES
Saída: 
COMPUTADORES
SÃO 
MÁQUINAS
POTENTES
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char frase[] = "COMPUTADORES SAO MAQUINAS POTENTES";
    int tam = strlen(frase);
    for (int i = 0; i < tam; i++)
    {
        if (frase[i] == ' ')
        {
            printf("\n");
        }
        else 
        {
            printf("%c", frase[i]);
        }
    }
    return 0;
}