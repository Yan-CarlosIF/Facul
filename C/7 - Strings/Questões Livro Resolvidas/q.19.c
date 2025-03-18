/*
Faça um programa que receba uma frase. Caso na frase apareça o nome de um mês do ano por extenso, 
deverá substituí-lo pelo seu número correspondente, como no exemplo.
Exemplo:
Frase: NO MÊS DE JANEIRO FAZ CALOR.
Nova frase: NO MÊS 01 FAZ CALOR.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void substituirMeses(char *frase);

int main()
{
    char frase[] = "NO MES DE JANEIRO FAZ CALOR";

    substituirMeses(frase);

    printf("\nResultado> %s", frase);
    return 0;
}

void substituirMeses(char *frase)
{
    char *meses[] = {"JANEIRO", "FEVEREIRO", "MARÇO", "ABRIL", "MAIO", "JUNHO", "JULHO", "AGOSTO", "SETEMBRO", "OUTUBRO", "NOVEMBRO", "DEZEMBRO"};
    char copia[200], resultado[200] = "", *numeros[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    strcpy(copia, frase);
    char *p = strtok(copia, " ,.");

    while (p != NULL)
    {  
        bool flag = false;
        for (int i = 0; i < 12; i++)
        {
            if (strcasecmp(p, meses[i]) == 0) 
            {
                strcat(resultado, numeros[i]);
                strcat(resultado, " ");
                flag = true;
            }
        }
        if (!flag && strcasecmp(p, "de") != 0)
        {
            strcat(resultado, p);
            strcat(resultado, " ");
        }
        p = strtok(NULL, " ,.");
    }
    
    strcpy(frase, resultado);
}