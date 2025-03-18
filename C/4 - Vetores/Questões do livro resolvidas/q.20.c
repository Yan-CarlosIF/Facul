#include <stdio.h>
/*Faça um programa que leia um vetor com cinco posições para números reais e, depois, um código 
inteiro. se o código for zero, finalize o programa; se for 1, mostre o vetor na ordem direta; se for 2, 
mostre o vetor na ordem inversa*/
int main()
{
    float vetor[5];
    int i,cod;
    printf("Insira 5 numeros:\n");
    for (i=0;i<5;i++)
    {
        scanf("%f",&vetor[i]);
    }
    do
    {
        printf("\nDigite o codigo\n1 - Mostrar o vetor na ordem direta\n2 - Mostrar o vetor na ordem reversa\n0 - Encerrar o programa\n:");
        scanf("%d",&cod);
    switch(cod)
    {
        case 0:
            break;
        case 1:
            printf("\nVetor na order direta:\n");
            for (i=0;i<5;i++)
            {
                printf("%.2f\n",vetor[i]);
            }
            break;
        case 2:
            printf("\nVetor na order reversa:\n");
            for (i=5-1;i>=0;i--)
            {
                printf("%.2f\n",vetor[i]);
            }
            break;
        default:;
    }
    } while (cod != 0);
    return 0;
}