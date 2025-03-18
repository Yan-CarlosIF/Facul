#include <stdio.h>

int main()
{
    char nome[100],sobrenome[100];
    printf("Digite seu primeiro nome:");
    scanf("%s",&nome);
    printf("\nDigite seu sobrenome:");
    fflush(stdin);
    scanf("%s",&sobrenome);

    printf("\nseu nome completo: %s %s",nome,sobrenome);
    return 0;
}