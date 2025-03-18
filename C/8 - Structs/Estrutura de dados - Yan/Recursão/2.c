#include <stdio.h>
#include <string.h>

/*
Questão 2: Verificar Palíndromo
Escreva uma função recursiva ehPalindromo(char palavra[], int inicio, int fim) que verifique se uma palavra é um palíndromo (uma palavra que se lê da mesma forma de frente para trás). A função deve retornar 1 se for um palíndromo e 0 caso contrário.

Dica: Compare os caracteres nas posições inicio e fim e continue verificando os caracteres internos.
*/

int palindromo(const char *str, int inicio, int fim) {
    if (inicio == fim) {
        return 1;
    }

    if (str[inicio] != str[fim]) {
        return 0;
    }

    return palindromo(str, inicio + 1, fim - 1);
}

int main() {
    char str[] = "radar";

    if (palindromo(str, 0, strlen(str) - 1)) {
        printf("eh palindromo!");
    } else {
        printf("nao eh palindromo!");
    }
    return 0;
}