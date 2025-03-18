/*
Faça um programa que receba uma frase e uma palavra. Caso a frase contenha a palavra ESCOLA,
deverá substituí-la pela palavra digitada.
Exemplo:
Frase: EU MORO PERTO DE UMA ESCOLA. MAS ESSA ESCOLA NÃO É A MELHOR. 
Palavra: PADARIA
Resposta: EU MORO PERTO DE UMA PADARIA. MAS ESSA PADARIA NÃO É A MELHOR
*/

#include <stdio.h>
#include <string.h>

void switchWords(char *frase, char *palavra)
{
    char fraseN[100] = "";
    char copia[strlen(frase) + 1];
    strcpy(copia, frase);
    char *p = strtok(copia, " ,.");

    while (p != NULL)
    {
        if (strcasecmp(p, "escola") == 0) 
        {
            strcat(fraseN, palavra);
            strcat(fraseN, " ");
        }
        else
        {
            strcat(fraseN, p);
            strcat(fraseN, " ");
        }
        p = strtok(NULL, " ,.");
    }
    fraseN[strlen(fraseN)] = '\0';

    strcpy(frase, fraseN);
}

int main()
{
    char frase[] = "EU MORO PERTO DE UMA ESCOLA. MAS ESSA ESCOLA NAO E A MELHOR";
    char palavra[50];

    printf("Digite uma palavra que deseja substituir 'escola' na frase:");
    gets(palavra);
    
    switchWords(frase, palavra);

    printf("\nFrase Nova: %s", frase);
    return 0;
}