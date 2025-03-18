#include <stdio.h>
#include <string.h>

void Tabela(int n);

int main()
{
    int num;
    do {
        printf("Digite um numero entre 1 e 9:");
        scanf("%d", &num);
    } while (num < 1 || num > 9);

    Tabela(num);
    return 0;
}

void Tabela(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char *espaco = "  ";
        for (int j = 1; j <= i; j++)
        {
            printf("%s%d", espaco, i * j);
        }
        printf("\n");
    }
}