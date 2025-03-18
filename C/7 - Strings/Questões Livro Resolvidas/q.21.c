/*
Faça um programa que receba o nome completo de uma pessoa e reescreva-o de acordo com o exemplo
a seguir.
Exemplo:
Nome: Maria Silva Costa 
Saída: Costa, M. S.
Nome: João Carlos Gomes Marques
Saída: Marques, J. C. G.
*/

#include <stdio.h>
#include <string.h>

void nomeAbreviado(char *nome);

int main()
{
    char nome[] = "Joao Carlos Gomes Marques";

    nomeAbreviado(nome);
    return 0;
}

void nomeAbreviado(char *nome)
{
    int i = 0;
    char copia[100], *split[100], resultado[100] = "";
    strcpy(copia, nome);
    char *n = strtok(copia, " ");

    while (n != NULL)
    {
        split[i++] = n;
        n = strtok(NULL, " ");
    }
    
    int tam = i;
    strcat(resultado, split[tam - 1]);
    strcat(resultado, ", ");

    for (int i = 0; i < tam - 1; i++)
    {
        char temp[2] = {split[i][0], '\0'};
        strcat(resultado, temp);
        strcat(resultado, ". ");
    }

    printf("\nResultado: %s", resultado);
}