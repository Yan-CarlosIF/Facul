#include <stdio.h>

int strprota(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int compara(char *str, char *str2)
{
    int cont = 0;
    if (strprota(str) != strprota(str2))
    {
        return 1;
    }

    for (int i = 0; i < strprota(str); i++)
    {
        if (str[i] != str2[i])
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    char frase[100], palavra[100], *palavras[100];
    int cont = 0, auxp = 0, auxl = 0;

    printf("Digite uma frase: ");
    gets(frase);

    printf("Agora, digite uma palavra que deseja procurar na sua frase: ");
    gets(palavra);

    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] != ' ')
        {
            palavras[auxp][auxl++] = frase[i];
        }
        else
        {
            palavras[auxp][auxl] = '\0';
            auxp++;
            auxl = 0;
        }
    }
    palavras[auxp][auxl] = '\0';

    for (int i = 0; i <= auxp; i++)
    {
        if (compara(palavra, palavras[i]) == 0)
        {
            cont++;
        }
    }

    printf("\nA palavra '%s' aparece %d vez(es) na frase", palavra, cont);

    return 0;
}
