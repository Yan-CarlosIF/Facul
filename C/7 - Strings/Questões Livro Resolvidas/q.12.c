/*
Faça um programa para criptografar uma frase dada pelo usuário, ou seja, a criptografia deverá inverter a frase.
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: ALOCSE AN UOTSE UE
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    int tam = strlen(frase);
    for (int i = 0; i < tam/2 ; i++)
    {
        char aux = frase[i];
        frase[i] = frase[tam - i - 1];
        frase[tam - i - 1] = aux;
    }

    printf("\nChama: %s", frase);
    return 0;
}
