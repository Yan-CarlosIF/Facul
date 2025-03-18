/*
Faça um programa para criptografar uma frase dada pelo usuário (a criptografia troca as vogais da
frase por *).
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: ** *ST** N* *SC*L*
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void criptografaVogais(char *frase) {
    for (int i = 0; i < strlen(frase); i++) {
        char l = tolower(frase[i]);
        if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
            frase[i] = '*';
        }
    }
}

int main() {
    char frase[50];

    printf("Digite uma frase:");
    gets(frase);

    printf("\nFrase: %s", frase);
    criptografaVogais(frase);
    printf("\nFrase criptografada: %s\n", frase);

    return 0;
}
