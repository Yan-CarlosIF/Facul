/*
Faça um programa que receba uma frase e troque a palavra ALUNO por ESTUDANTE e a palavra
ESCOLA por UNIVERSIDADE.
Exemplo: EU SOU ALUNO DA ESCOLA
Saída: EU SOU ESTUDANTE DA UNIVERSIDADE
*/

#include <stdio.h>
#include <string.h>

void trocaPalavras(char *frase, char *fraseTrocada)
{
    char *palavras = strtok(frase, " ,.");

    while (palavras != NULL)
    {
        if (stricmp(palavras, "aluno") == 0)
        {
            strcat(fraseTrocada, "Estudante");
            strcat(fraseTrocada, " ");
        }
        else if (stricmp(palavras, "escola") == 0)
        {
            strcat(fraseTrocada, "Universidade");
            strcat(fraseTrocada, " ");
        }
        else
        {
            strcat(fraseTrocada, palavras);
            strcat(fraseTrocada, " ");
        }
        palavras = strtok(NULL, " ,.");
    }

    if (strlen(fraseTrocada) > 0 && fraseTrocada[strlen(fraseTrocada) - 1] == ' ')
    {
        fraseTrocada[strlen(fraseTrocada) - 1] == '\0';
    }
}

int main()
{
    char frase[100], fraseTrocada[200] = "";

    printf("Digite uma frase:");
    gets(frase);

    trocaPalavras(frase, fraseTrocada);

    printf("\nFrase: %s", fraseTrocada);
    return 0;
}
