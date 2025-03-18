#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void isPalindrom(char *palavra)
{
    int tam = strlen(palavra);
    char PalavraInvertida[20];
    strcpy(PalavraInvertida, palavra);

    for (int i = 0; i < tam / 2; i++)
    {
        char aux = PalavraInvertida[i];
        PalavraInvertida[i] = PalavraInvertida[tam - i - 1];
        PalavraInvertida[tam - i - 1] = aux;
    }

    if (strcmp(palavra, PalavraInvertida) == 0)
    {
        printf("eh palin");
    }
    else
    {
        printf("nao eh palin");
    }
}

int main()
{
    char palavra[20];

    printf("Digite um palavra:");
    gets(palavra);

    isPalindrom(palavra);

    if (strcasecmp("OI", "oi") == 0)
    {
        printf("São iguais");
    }
    else
    {
        printf("São diferente");
    }
}