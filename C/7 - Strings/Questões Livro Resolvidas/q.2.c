// Faça um programa que receba uma frase, calcule e mostre a quantidade de consoantes da frase digita-
// da. O programa deverá contar consoantes maiúsculas e minúsculas.
// Solução:
// ■■Digitar uma frase. 
// ■■Pegar o tamanho da frase. 
// ■■Percorrer a frase, pegando caractere por caractere. 
// ■■Comparar cada caractere com as consoantes (maiúsculas e minúsculas). 
// ■■Quando encontrar uma consoante, acrescentar um na quantidade.

#include <stdio.h>
#include <ctype.h>

int len(char *string) {
    int cont = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        cont++;
    }

    return cont;
}

int contarConsoantes(char *frase)
{
    int cont = 0;

    for (int i = 0; i < len(frase); i++)
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
    frase[len(frase) - 1] = '\0';

    int cont = contarConsoantes(frase);

    printf("\nQuantidade de consoantes da frase '%s': %d\n", frase, cont);
    return 0;
}
