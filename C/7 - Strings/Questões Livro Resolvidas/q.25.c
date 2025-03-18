/*
Faça um programa que receba uma frase e conte quantos verbos existem nela, considerando que os
verbos terminam em R
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contVerbos(char *frase)
{
    int cont = 0;
    char copia[500];
    strcpy(copia, frase);
    char *p = strtok(copia, " ,.");

    while (p != NULL)
    {
        if (tolower(p[strlen(p) - 1]) == 'r')
        {
            cont++;
        }
        p = strtok(NULL, " ,.");
    }
    
    return cont;
}

int main()
{
    char frase[500];

    printf("Digite uma frase:");
    gets(frase);

    int cont = contVerbos(frase);
    printf("\nQuantidade de verbos na frase: '%s': %d", frase, cont);
    return 0;
}