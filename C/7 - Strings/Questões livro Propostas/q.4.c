/*
Faça um programa que receba uma frase, calcule e mostre a quantidade de palavras da frase digitada. Antes 
de contar a quantidade de palavras da frase, esta deverá passar pelas seguintes correções:
a) Eliminação de espaços no início da frase. 
b) Eliminação de espaços no fim da frase. 
c) Eliminação de espaços duplicados entre palavras
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int contPalavras(char *str);

int main()
{
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    int cont = contPalavras(frase);

    printf("\n%d", cont);
    return 0;
}

int contPalavras(char *str)
{
    int i = 0, j = 0, cont = 1;
    int tam = strlen(str);
    bool spaceFound = false;

    while (isspace(str[i])) 
    {
        i++;
    }

    while (i < tam) 
    {
        if (!isspace(str[i])) 
        {
            str[j++] = str[i];
            spaceFound = false;
        } 
        else if (!spaceFound) 
        {
            str[j++] = ' ';
            spaceFound = true;
        }
        i++;
    }

    if (j > 0 && str[j - 1] == ' ') 
    {
        j--;
    }
    str[j] = '\0';

    int tam = strlen(str);
    for (int i = 0; i < tam; i++)
    {
        if (str[i] == ' ')
        {
            cont++;
        }
    }

    return cont;
}