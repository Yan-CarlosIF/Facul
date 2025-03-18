/*
Faça um programa para criptografar uma frase dada pelo usuário, ou seja, a criptografia deverá inverter cada palavra da frase.
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: UE UOTSE AN ALOCSE
*/

#include <stdio.h>
#include <string.h>

void invertePalavras(char *str, char *frase) 
{
    char *palavras = strtok(str, " ,.");

    while (palavras != NULL)
    {
        int tam = strlen(palavras);
        for (int i = 0; i < tam / 2; i++)
        {
            char aux = palavras[i];
            palavras[i] = palavras[tam - i - 1];
            palavras[tam - i - 1] = aux;
        }
        strcat(frase, palavras);
        strcat(frase, " ");

        palavras = strtok(NULL, " ,.");
    }
}

int main()
{
    char frase[100], fraseI[100] = "";

    printf("Digite uma frase:");
    gets(frase);

    invertePalavras(frase, fraseI);

    printf("\nFrase invertida: %s\n", fraseI);
    return 0;
}