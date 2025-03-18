// Atividade: Crie um programa que recebe um array de números inteiros e a quantidade de elementos. 
//Use uma função com ponteiros para encontrar o maior valor e o menor valor nesse array, retornando ambos para o programa principal.
// Instruções:
// No programa principal, crie um array de inteiros e peça ao usuário para inserir os valores.
// Crie uma função que receba o array e sua quantidade de elementos. A função deve retornar o maior e o menor valor usando ponteiros.
// Exiba o maior e o menor valor no programa principal.

#include <stdio.h>
#include <stdlib.h>

// Atividade: Crie um programa que recebe um array de números inteiros e a quantidade de elementos. Use uma função com ponteiros para encontrar o maior valor e o menor valor nesse array, retornando ambos para o programa principal.
// Instruções:
// No programa principal, crie um array de inteiros e peça ao usuário para inserir os valores.
// Crie uma função que receba o array e sua quantidade de elementos. A função deve retornar o maior e o menor valor usando ponteiros.
// Exiba o maior e o menor valor no programa principal.

void maiorMenor(int numeros[], int tamanho, int *maior, int *menor)
{

    *menor = 10000;
    *maior = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (numeros[i] > *maior)
        {
            *maior = numeros[i];
        }
        if (numeros[i] < *menor)
        {
            *menor = numeros[i];
        }
    }
}

int main()
{
    int *listaNumeros;
    int n;
    int maior, menor;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    listaNumeros = (int *)malloc(n * (sizeof(int)));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &listaNumeros[i]);
    }

    maiorMenor(listaNumeros, n, &maior, &menor);
    printf("%d\n", maior);
    printf("%d", menor);

    return 0;
}