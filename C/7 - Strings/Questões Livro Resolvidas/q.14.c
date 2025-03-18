/*
Faça um programa que receba uma frase com letras minúsculas e converta a primeira letra de cada 
palavra da frase para maiúscula.
Exemplo:
Entrada: fazer exercícios faz bem. 
Saída: Fazer Exercícios Faz Bem.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{   
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    int tam = strlen(frase);
    for (int i = 0; i < tam; i++)
    {   if (i == 0) 
        {
            frase[i] = toupper(frase[i]);
        }
        if ((frase[i] == ' ' || frase[i] == ',' || frase[i] == '.' || frase[i] == '\n') && i < tam)
        {
            frase[i + 1] = toupper(frase[i + 1]);
        }
    }

    printf("\nFrase: %s\n", frase);
    return 0;
}