/*
Faça um programa que receba uma frase, calcule e mostre a quantidade de vezes que a palavra AULA
aparece na frase digitada.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contAula(char *frase)
{
    int cont = 0;
    char copiaF[100];
    strcpy(copiaF, frase);
    char *palavras = strtok(copiaF, " .,");

    while (palavras != NULL)
    {
        if (stricmp(palavras, "aula") == 0)
        {
            cont++;
        }
        palavras = strtok(NULL, " .,");
    }

    return cont;
}

int main()
{
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    int cont = contAula(frase);

    printf("\nQuantidade de vezes que a palavra 'Aula' apareceu na frase '%s': %d\n", frase, cont);

    return 0;
}
