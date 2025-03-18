#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void removeExcessSpaces(char *str) {
    int i = 0, j = 0;
    int len = strlen(str);
    bool spaceFound = false;

    // Pula espaços no início
    while (isspace(str[i])) 
    {
        i++;
    }
    while (i < len) 
    {
        // Copia o caractere atual se não for um espaço
        if (!isspace(str[i])) 
        {
            str[j++] = str[i];
            spaceFound = false; // Reinicia a flag de espaço
        } 
        // Se for um espaço e ainda não copiamos um espaço antes, copia um
        else if (!spaceFound) 
        {
            str[j++] = ' ';
            spaceFound = true; // Marca que encontramos um espaço
        }
        i++;
    }

    if (j > 0 && str[j - 1] == ' ') 
    {
        j--;
    }
    str[j] = '\0';
}

int main()
{
    char frase[100];

    printf("Digite uma frase:");
    gets(frase);

    removeExcessSpaces(frase);

    printf("\nChama: %s", frase);
    return 0;
}