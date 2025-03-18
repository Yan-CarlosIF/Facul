#include <stdio.h>
#include <string.h>

// Questão 9: Inverter uma String
// Escreva uma função recursiva inverteString(char str[], int inicio, int fim) que inverta uma string, alterando os caracteres in-place. Por exemplo, ao receber "hello", a string deve ser transformada em "olleh".

// Dica: Troque os caracteres nas posições inicio e fim, e chame a função para os caracteres internos.

void inverteString(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    char aux = str[inicio];
    str[inicio] = str[fim];
    str[fim] = aux;

    return inverteString(str, inicio + 1, fim - 1);
}

int main() {
    char string[] = "Hello";
    printf("String; %s\n", string);

    inverteString(string, 0, strlen(string) - 1);
    
    printf("Invertida: %s\n", string);
    return 0;
}