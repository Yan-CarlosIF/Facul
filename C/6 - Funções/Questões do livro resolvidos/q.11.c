#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define hab 2

float mediaIdade(int *idade, char *corOlhos, char *corCabelo, int tam);
int maiorIdade(int *idade, int tam);
int contagem(int *idade, char *sexo, char *corOlhos, char *corCabelo, int tam);

int main()
{
    char sexo[hab], corOlhos[hab], corCabelo[hab];
    int idade[hab];

    for (int i = 0; i < hab; i++) //Que leia esses dados, armazenando-os em vetores.
    {
        do {
            printf("Digite o sexo do %d habitante:", i + 1);
            fflush(stdin);
            scanf("%c", &sexo[i]);
        } while (tolower(sexo[i]) != 'm' && tolower(sexo[i]) != 'f');

        do {
            printf("Digite a cor dos olhos do %d habitante:", i + 1);
            fflush(stdin);
            scanf("%c", &corOlhos[i]);
        } while (tolower(corOlhos[i]) != 'a' && tolower(corOlhos[i]) != 'c');

        do {
            printf("Digite a cor dos cabelos do %d habitante:", i + 1);
            fflush(stdin);
            scanf("%c", &corCabelo[i]);
        } while (tolower(corCabelo[i]) != 'c' && tolower(corCabelo[i]) != 'p' && tolower(corCabelo[i]) != 'l');

        printf("Digite a idade do %d habitante:", i + 1);
        scanf("%d", &idade[i]);
    }

    printf("\nMedia de idade das pessoas com olhos castanhos e cabelos pretos: %.1f", mediaIdade(idade, corOlhos, corCabelo, hab));
    printf("\nMaior idade entre os habitantes: %d", maiorIdade(idade, hab));
    printf("\nQuantidade de pessoas do sexo feminino com idade entre 18 e 35 anos e que tenham olhos azuis e cabelos louros: %d", contagem(idade, sexo, corOlhos, corCabelo, hab));
    return 0;
}

/* Que determine e devolva ao programa principal a média de idade das pessoas com olhos castanhos e cabelos pretos. */
float mediaIdade(int *idade, char *corOlhos, char *corCabelo, int tam)
{
    int cont = 0;
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {
        if (tolower(corOlhos[i]) == 'c' && tolower(corCabelo[i]) == 'p')
        {
            cont++;
            soma += idade[i];
        }
    }
    if (cont > 0)
    {
        return soma /(float)cont;
    } 
    else 
    {
        return 0;
    }
}

// Que determine e devolva ao programa principal a maior idade entre os habitantes.
int maiorIdade(int *idade, int tam)
{
    int maior = idade[0];

    for (int i = 0; i < tam; i++)
    {
        if (maior < idade[i])
        {
            maior = idade[i];
        }
    }

    return maior;
}

/* Que determine e devolva ao programa principal a quantidade de indivíduos do sexo feminino com
idade entre 18 e 35 anos (inclusive) e que tenham olhos azuis e cabelos louros. */
int contagem(int *idade, char *sexo, char *corOlhos, char *corCabelo, int tam)
{
    int cont = 0;

    for (int i = 0; i < tam; i++)
    {
        if (tolower(sexo[i]) == 'f' && idade[i] >= 18 && idade[i] <= 35 && tolower(corOlhos[i]) == 'a' && tolower(corCabelo[i]) == 'l')
        {
            cont++;
        }
    }

    return cont;
}