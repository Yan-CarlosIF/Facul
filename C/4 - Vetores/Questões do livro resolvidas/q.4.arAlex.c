#include <stdio.h>
#include <stdbool.h>
#define tam 2

int main() {
    char nomes[tam][50];

    for (int i = 0; i < tam; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        gets(nomes[i]);
    }

    int achou;
    char nome[50];
    printf("Digite o nome da pessoa que deseja procurar: ");
    gets(nome);
    
    for (int i = 0; i < tam; i++) {
        achou = true;
        for (int j = 0; nomes[i][j] != '\0'; j++) {
            if (nomes[i][j] != nome[j]) {
                achou = false;
                break;
            }
        }

        if (achou) {
            printf("\nACHEI\n");
            break;
        }
    }
    
    if (!achou) {
        printf("\nNAO ACHEI\n");
    }
    return 0;
}