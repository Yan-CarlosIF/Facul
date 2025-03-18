/*
Faça um programa que receba uma palavra e verifique se ela constitui um palíndromo, ou seja, se a 
palavra escrita do fim para o começo fica igual à palavra escrita do começo para o fim.
Exemplos:
ARARA 
ANA 
MIRIM
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char palavra[] = "ARARA";
    int tam = strlen(palavra);
    char palavraI[tam + 1];

    for (int i = 0; i < tam; i++)
    {
        palavraI[i] = palavra[tam - i - 1];
    }
    palavraI[tam] = '\0';
    
    if (strcmp(palavra, palavraI) == 0) 
    {
        printf("eh um palindromo!");
    }
    else
    {
        printf("Nao eh um palindromo");
    }
    return 0;
}