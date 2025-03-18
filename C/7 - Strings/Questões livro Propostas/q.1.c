/*
Faça um programa para criptografar uma frase dada pelo usuário. Na criptografia, a frase deverá ser invertida
e as consoantes deverão ser trocadas por #.
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: A#O##E A# UO##E UE
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trocaConsoante(char *frase); 

int main()
{
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    trocaConsoante(frase);

    printf("\nFrase: %s", frase);
    return 0;
}

void trocaConsoante(char *frase) 
{
    int tam = strlen(frase);
    for (int i = 0; i < tam / 2; i++)
    {
        char aux = frase[i];
        frase[i] = frase[tam - i -1];
        frase[tam - i - 1] = aux;
    }
    
    for (int i = 0; i < tam; i++)
    {   
        char letra = tolower(frase[i]);
        if (isalpha(letra) && letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u')
        {
            frase[i] = '#';
        }
    }
}   