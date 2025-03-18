/*
Faça um programa que receba uma frase e uma palavra, calcule e mostre a quantidade de vezes que a
palavra digitada aparece na frase.
Exemplo:
Frase: EU ESTOU NA ESCOLA E A ESCOLA É LEGAL.
Palavra: ESCOLA
Resposta: A palavra ESCOLA apareceu 2 vezes na frase.
*/

#include <stdio.h>
#include <string.h>

int contPalavra(char *frase, char *palavra)
{
    int cont = 0;
    char copia[100];
    strcpy(copia, frase);
    char *palavras = strtok(frase, " ,.");

    while (palavras != NULL)
    {
        if (stricmp(palavras, palavra) == 0)
        {
            cont++;
        }
        palavras = strtok(NULL, " ,.");
    }

    return cont;
}

int main()
{
    char frase[100], palavra[20];

    printf("Digite uma frase:");
    gets(frase);
    printf("Digite uma palavra que deseja buscar na frase:");
    gets(palavra);

    int cont = contPalavra(frase, palavra);

    printf("\nQuantidade de vezes que a palavra '%s' apareceu na frase: %d\n", palavra, cont);
    return 0;
}
