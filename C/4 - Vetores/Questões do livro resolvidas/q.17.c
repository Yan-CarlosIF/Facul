#include <stdio.h>
/*Faça um programa que receba seis números inteiros e mostre: 
■ os números pares digitados; 
■ a soma dos números pares digitados; 
■ os números ímpares digitados; e
■ a quantidade de números ímpares digitados.*/
int main()
{
    int i,vetor[6],soma_par=0,cont_impar=0;
    printf("Digite 6 numeros:\n");
    for (i=0;i<6;i++)
    {
        scanf("%d",&vetor[i]);
    }
    printf("\nOs numeros pares:\n");
    for (i=0;i<6;i++)
    {
        if (vetor[i]%2==0)
        {
            printf("%d\n",vetor[i]);
            soma_par+=vetor[i];        
        }
    }
    printf("Soma dos pares = %d\n",soma_par);
    printf("\nOs numeros impares:\n");
    for (i=0;i<6;i++)
    {
        if (vetor[i]%2!=0)
        {
            printf("%d\n",vetor[i]);
            cont_impar++;
        }
    }
    printf("Quantidade de impares = %d",cont_impar);
    return 0;
}