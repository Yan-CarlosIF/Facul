#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100], *split[100], fraseOrdenada[100] = "";

    printf("Digite uma frase:");
    gets(frase);

    char *palavras = strtok(frase, " ");
    int tam = 0;
    while (palavras != NULL)
    {
        split[tam++] = palavras;
        palavras = strtok(NULL, " ");
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = i; j < tam; j++)
        {
            if (split[i][0] > split[j][0])
            {
                char *aux = split[i];
                split[i] = split[j];
                split[j] = aux;
            }
        }

        if (i == tam - 1)
        {
            strcat(fraseOrdenada, split[i]);
        }
        else
        {
            strcat(fraseOrdenada, split[i]);
            strcat(fraseOrdenada, " ");
        }
    }

    printf("\nFrase em Ordem Alfabetica: %s\n", fraseOrdenada);

    return 0;
}
