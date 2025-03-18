/*
Faça um programa para criptografar uma frase em que cada caractere deverá ser substituído pelo caractere que está três posições à sua frente na tabela ASCII. 
Os três últimos caracteres da tabela ASCII
deverão ser substituídos pelos três primeiros.
Exemplo:
BONECO ZABUMBA
ERQHFR CDEXPED
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100] = "BONECO ZABUMBA";
    
    int tam = strlen(str);
    for (int i = 0; i < tam; i++) 
    {   
        if (str[i] == ' ')
        {
            printf("%c", str[i]);
        } 
        else if (str[i] >= 'X' && str[i] <= 'Z')
        {
            printf("%c", str[i] - 23);
        }
        else 
        {
            printf("%c", str[i] + 3);
        }
    }

    return 0;
}