/*
Faça um programa que receba uma frase e gere uma nova frase, duplicando cada caractere da frase digitada.
Exemplo:
Frase: PROGRAMAR É BOM
Saída: PPRROOGGRRAAMMAARR ÉÉ BBOOMM
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void novaFrase(char *frase)
{   
    int tam = strlen(frase);
    char resultado[200] = "";

    for (int i = 0; i < tam; i++)
    {
        if (isspace(frase[i]))
        {  
            char letra[2] = {frase[i], '\0'};
            strcat(resultado, letra);
        }
        else if (isalpha(frase[i])) 
        {
            char letra[2] = {frase[i], '\0'};
            strcat(resultado, letra);
            strcat(resultado, letra);
        }
    }

    printf("frase: %s\nsaida: %s", frase, resultado);
}

int main()
{
    char frase[] = "PROGRAMAR E BOM";

    novaFrase(frase);
}