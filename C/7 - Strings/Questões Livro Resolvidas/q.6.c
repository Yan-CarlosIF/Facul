/*
Faça um programa que receba duas frases e gere uma terceira que represente a combinação das palavras das duas frases recebidas.
Exemplo:
Frase 1: Hoje está um belo dia
Frase 2: Talvez chova amanhã
Saída: Hoje talvez está chova um amanhã belo dia
*/

#include <stdio.h>
#include <string.h>

void fraseGerada(char *str1, char *str2, char *str3)
{

    char *palavras1[50], *palavras2[50];
    int i = 0, j = 0, k = 0;

    char *token = strtok(str1, " ");
    while (token != NULL)
    {
        palavras1[i++] = token;
        token = strtok(NULL, " ");
    }

    token = strtok(str2, " ");
    while (token != NULL)
    {
        palavras2[j++] = token;
        token = strtok(NULL, " ");
    }

    while (k < i || k < j)
    {
        if (k < i)
        {
            strcat(str3, palavras1[k]);
            strcat(str3, " ");
        }

        if (k < j)
        {
            strcat(str3, palavras2[k]);
            strcat(str3, " ");
        }
        k++;
    }

    if (strlen(str3) > 0 && str3[strlen(str3) - 1] == ' ')
    {
        str3[strlen(str3) - 1] = '\0';
    }
}

int main()
{

    char frase[50], frase2[50], frase3[100] = "";

    printf("Digite a 1 frase:");
    gets(frase);
    printf("Digite a 2 frase:");
    fflush(stdin);
    gets(frase2);

    fraseGerada(frase, frase2, frase3);

    printf("\nFrase Gerada: %s\n", frase3);
    return 0;
}
