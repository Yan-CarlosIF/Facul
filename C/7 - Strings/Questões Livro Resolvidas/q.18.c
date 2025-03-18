/*
Faça um programa que se comporte como vírus, ou seja, que duplique cada uma das palavras digitadas
pelo usuário.
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: EU EU ESTOU ESTOU NA NA ESCOLA ESCOLA
Solução:
■ Digitar uma frase.
■ Pegar o tamanho da frase.
■ Percorrer a frase, pegando caractere por caractere.
■ Comparar cada caractere com espaço em branco.
■ Quando encontrar espaço ou o fim da frase, foi encontrado o fim de uma palavra. Copiar a palavra encontrada.
■ Inserir a palavra encontrada na frase duas vezes.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void duplicarPalavras(char *str)
{
    char copia[200], resultado[200] = "";
    strcpy(copia, str);
    char *p = strtok(copia, " ,.");

    while (p != NULL)
    {
        strcat(resultado, p);
        strcat(resultado, " ");
        strcat(resultado, p);
        strcat(resultado, " ");
        p = strtok(NULL, " ,.");
    }
    
    strcpy(str, resultado);
}

int main()
{
    char string[200];

    printf("Digite uma frase:");
    gets(string);

    duplicarPalavras(string);

    printf("\nResultado: %s", string);
    return 0;
}