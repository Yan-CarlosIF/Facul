/*
Faça um programa que receba um nome e gere como saída o nome digitado e seu login. Lembre-se
de respeitar as letras minúsculas e maiúsculas, já que o login será sempre com letras minúsculas. A 
regra para geração do login é: a primeira letra do nome e, caso exista apenas um sobrenome, deve-se 
acrescentá-lo; caso existam dois sobrenomes, deve-se gerar a primeira letra do nome, mais a primeira 
letra do primeiro sobrenome, seguido do último sobrenome; caso existam três ou mais sobrenomes, 
deve-se proceder como na situação anterior, considerando o nome, o primeiro sobrenome e o último sobrenome.
Exemplos:
Nome: Pedro Hansdorf 
Login: phansdorf
Nome: Robson Soares Silva
Login: rssilva
Nome: Jaqueline Oliveira Fernandes Espanhola
Login: joespanhola
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gerarLogin(char *nome, char *senha);
int contarPalavras(char *nome);

int main()
{
    char nome[] = "Robson Soares Silva";
    char senha[100] = "";

    gerarLogin(nome, senha);
    printf("cont: %d\n", contarPalavras(nome));
    printf("Nome: %s\n", nome);
    printf("Login: %s\n", senha);

    return 0;
}

void gerarLogin(char *nome, char *senha)
{
    int i = 0, tam = contarPalavras(nome);
    char copia[100];
    strcpy(copia, nome);
    char *p = strtok(copia, " ,.");

    while (p != NULL)
    {
        if (tam == 2)
        {
            if (i == 0)
            {
                senha[0] = tolower(p[0]);
            }
            if (i == tam - 1)
            {
                p[0] = tolower(p[0]);
                strcat(senha, p);
            }
        }
        else if (tam > 2)
        {
            if (i < 2)
            {
                senha[i] = tolower(p[0]);
            } 
            else if (i == tam - 1)
            {
                p[0] = tolower(p[0]);
                strcat(senha, p);
            }
        }
        p = strtok(NULL, " ,.");
        i++;
    }
}

int contarPalavras(char *nome)
{
    int cont = 1;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] == ' ' || nome[i] == ',' || nome[i] == '\0')
        {
            cont++;
        }
    }

    return cont;
}
