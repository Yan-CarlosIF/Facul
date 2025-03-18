#include <stdio.h>
/*Faça um programa que preencha um vetor com dez números inteiros, calcule e mostre os números su
periores a cinquenta e suas respectivas posições. O programa deverá mostrar mensagem se não existir 
nenhum número nessa condição.*/
int main() {
    int i,vetor[10],cont=0;
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero:",i+1);
        scanf("%d",&vetor[i]);
        printf("\n");
        if (vetor[i]>50) {
            cont++;
        }
    }
    if (cont==0) {
        printf("\nNenhum numero digitado eh maior que 50!");
    } else {
        printf("\nNumeros superiores a 50:\n");
        for (i = 0; i < 10; i++) {
            if (vetor[i]>50) {
                printf("%d\n",vetor[i]);
            } 
        }
    }
    return 0;
}