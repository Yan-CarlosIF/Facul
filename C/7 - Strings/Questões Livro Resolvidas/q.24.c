/*
Faça um programa que receba um verbo regular terminado em AR e mostre sua conjugação no presente.
Exemplo:
Verbo: andar
Eu ando
Tu andas
Ele anda
Ela anda
Nós andamos
Vós andais
Eles andam
Elas andam
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void conjugaVerbo(char *verbo);

int main()
{
    char verbo[] = "andar";

    conjugaVerbo(verbo);
    return 0;
}

void conjugaVerbo(char *verbo)
{
    int tam = strlen(verbo);
    if (tam < 2 || strcmp(&verbo[tam - 2], "ar") != 0)
    {
        printf("ERROR: verbo deve terminar em 'ar'!");
    }
    else 
    {
        char radical[100];
        strncpy(radical, verbo, tam - 2);
        radical[tam - 2] = '\0';

        printf("Eu %so\n", radical);
        printf("Tu %sas\n", radical);
        printf("Ele %sa\n", radical);
        printf("Ela %sa\n", radical);
        printf("Nos %samos\n", radical);
        printf("Vos %sais\n", radical);
        printf("Eles %sam\n", radical);
        printf("Elas %sam\n", radical);
    }
}