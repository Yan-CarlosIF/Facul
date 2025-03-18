/*
Faça um programa que receba uma frase e, a cada ocorrência da palavra TECLADO, insira o texto
OU MOUSE.
Exemplo:
Frase: PODE-SE UTILIZAR O TECLADO PARA ENTRADA DE DADOS.
Resposta: PODE-SE UTILIZAR O TECLADO OU MOUSE PARA ENTRADA DE DADOS.
*/

#include <stdio.h>
#include <string.h>

void concatenaTeclado(char *frase, char *fraseNova)
{
    char *palavras = strtok(frase, " ,.");

    while (palavras != NULL)
    {
        if (stricmp(palavras, "teclado") == 0)
        {
            strcat(fraseNova, palavras);
            strcat(fraseNova, " ou Mouse ");
        }
        else
        {
            strcat(fraseNova, palavras);
            strcat(fraseNova, " ");
        }
        palavras = strtok(NULL, " ,.");
    }
}

int main()
{
    char str[200], fraseNova[200] = "";

    printf("Digite uma frase:");
    gets(str);

    concatenaTeclado(str, fraseNova);

    printf("\nFrase Modificada: %s", fraseNova);
    return 0;
}
