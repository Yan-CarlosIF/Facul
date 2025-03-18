/* Faça um programa que receba uma frase, calcule e mostre a quantidade de palavras da frase digitada. */
#include <stdio.h>
#include <string.h>

int contPalavras(char *frase) {
    int cont = 0;
    char *palavra, fraseCopia[50];
    strcpy(fraseCopia, frase);
    palavra = strtok(fraseCopia, " ");

    while (palavra != NULL) {
        cont++;
        palavra = strtok(NULL, " ");
    }

    return cont;
}

int main() {
    char frase[50];

    printf("Digite uma frase:");
    gets(frase);

    int cont = contPalavras(frase);

    printf("Quantidade de palavras da frase '%s': %d", frase, cont);
    return 0;
}

