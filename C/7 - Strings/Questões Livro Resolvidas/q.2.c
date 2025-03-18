#include <stdio.h>
#include <ctype.h>

int contarConsoantes(char *frase)
{
    int cont = 0;
    for (int i = 0; i < strlen(frase); i++)
    {
        char letra = tolower(frase[i]);

        if (letra >= 'a' && letra <= 'z' && letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u')
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

    int cont = contarConsoantes(frase);

    printf("\nQuantidade de consoantes da frase '%s': %d\n", *frase, cont);
    return 0;
}
