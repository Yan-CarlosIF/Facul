#include <stdio.h>
#include <ctype.h>

int contarVogais(char *frase)
{
    int cont = 0;

    for (int i = 0; i < strlen(frase); i++)
    {
        char letra = tolower(frase[i]);

        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    char frase[50];

    printf("Digite uma frase:");
    fgets(frase, sizeof(frase), stdin);
    frase[strlen(frase) - 1] = '\0';

    int cont = contarVogais(frase);

    printf("\nQuantidade de vogais da frase '%s': %d\n", frase, cont);
    return 0;
}