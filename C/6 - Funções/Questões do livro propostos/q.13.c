/*
Foi realizada uma pesquisa entre 15 habitantes de uma região. Os dados coletados de cada habitante 
foram: idade, sexo, salário e número de filhos. 
Faça uma sub-rotina que leia esses dados armazenando-os em vetores. Depois, crie sub-rotinas que 
recebam esses vetores como parâmetro e retornem a média de salário entre os habitantes, a menor e a 
maior idade do grupo e a quantidade de mulheres com três filhos que recebem até R$ 500,00 (utilize 
uma sub-rotina para cada cálculo).
*/

#include <stdio.h>
#include <ctype.h>
#define hab 2

void lerDados(int *idades, char *sexo, float *salario, int *numFilhos, int tam);
float mediaSalario(float *salarios, int tam);
void extremosIdades(int *maior, int *menor, int *idades, int tam);
int contagem(char *sexo, int *numFilhos, float *salario, int tam);

int main() 
{
    char sexo[hab];
    int idades[hab], numFilhos[hab], maior, menor;
    float salarios[hab];

    printf("Digite os dados dos %d habitantes:\n", hab);
    lerDados(idades, sexo, salarios, numFilhos, hab);

    float media = mediaSalario(salarios, hab);
    extremosIdades(&maior, &menor, idades, hab);
    int cont = contagem(sexo, numFilhos, salarios, hab);

    printf("\nMedia dos salario = %.2f", media);
    printf("\nMaior idade: %d\nMenor idade: %d", maior, menor);
    printf("\nQuantidade de mulheres com tres filhos que recebem ate R$ 500,00: %d\n", cont);
}

void lerDados(int *idades, char *sexo, float *salario, int *numFilhos, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite a idade do %d habitante:", i + 1);
        scanf("%d", &idades[i]);
        do 
        {
        printf("Digite o sexo do %d habitante:", i + 1);
        fflush(stdin);
        scanf(" %c", &sexo[i]);
        } while (tolower(sexo[i]) != 'f' && tolower(sexo[i]) != 'm');
        printf("Digite o salario do %d habitante:", i + 1);
        scanf("%f", &salario[i]);
        printf("Digite a quantidade de filhos do %d habitante:", i + 1);
        scanf("%d", &numFilhos[i]);
    }
}

float mediaSalario(float *salarios, int tam)
{
    float somaSalarios = 0;

    for (int i = 0; i < tam; i++)
    {
        somaSalarios += salarios[i];
    }

    return somaSalarios/(float)tam;
}

void extremosIdades(int *maior, int *menor, int *idades, int tam)
{
    *maior = idades[0];
    *menor = idades[0];

    for (int i = 0; i < tam; i++)    
    {
        if (*maior < idades[i])
        {
            *maior = idades[i];
        }
        if (*menor > idades[i])
        {
            *menor = idades[i];
        }
    }
}

int contagem(char *sexo, int *numFilhos, float *salario, int tam)
{
    int cont = 0;

    for (int i = 0; i < tam; i++)
    {
        if (tolower(sexo[i]) == 'f' && numFilhos[i] >= 3 && salario[i] <= 500)
        {
            cont++;
        }
    }

    return cont;
}