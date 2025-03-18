/*
Faça um programa que receba o nome completo de uma pessoa e mostre os nomes intermediários entre
o primeiro nome e o último sobrenome abreviados.
Exemplo:
Nome: Maria Silva Costa 
Saída: Maria S. Costa
Nome: João Carlos Gomes Marques
Saída: João C. G. Marques
*/

#include <stdio.h>
#include <string.h>

int contPalavras(char *str);
void nomeAbreviado(char *nome);

int main()
{
    char nome[] = "Maria Silva Costa";

    nomeAbreviado(nome);
    return 0;
}

void nomeAbreviado(char *nome)
{
    int i = 0, tam = contPalavras(nome);
    char copia[strlen(nome) + 1];
    strcpy(copia, nome);
    char *n = strtok(copia, " ");

    while (n != NULL)
    {
        if (i == 0 || i == tam - 1)
        {
            printf("%s ", n);
        } 
        else 
        {
            printf("%c. ", n[0]);
        }
        i++;
        n = strtok(NULL, " ");
    }
}

int contPalavras(char *str) 
{
    int cont = 1, tam = strlen(str);

    for (int i = 0; i < tam; i++) 
    {
        if (str[i] == ' ')
        {
            cont++;
        }
    }

    return cont;
}