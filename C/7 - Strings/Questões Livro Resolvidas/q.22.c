/*
Faça um programa que receba um nome e gere um login e uma senha. O login deverá ser composto
pela primeira letra de cada nome em letras maiúsculas e as mesmas letras minúsculas; a senha será 
composta pela representação ASCII de cada letra do login.
Exemplo:
Nome: Ana Beatriz Costa 
Login: ABCabc
Senha: 656667979899
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void LoginSenha(char *nome, char *login)
{
    char copia[100];
    strcpy(copia, nome);
    char *p = strtok(copia, " ");
    

    while (p != NULL)
    {
        login[strlen(login)] = toupper(p[0]);
        p = strtok(NULL, " ");
    }

    int tam = strlen(login);
    for (int i = 0; i < tam; i++)
    {
        login[tam + i] = tolower(login[i]);
    }
 
}

int main()
{
    char nome[100] = "Ana Beatriz Costa", login[50] = "";

    LoginSenha(nome, login);

    printf("\n%s\n%s\n", nome, login);
    int tam = strlen(login);
    
    for (int i = 0; i < tam; i++)
    {
        printf("%d", login[i]);
    }
    return 0;
}