#include <stdio.h>
/*Faça um programa que leia dois vetores (A e B) com cinco posições para números inteiros. O programa 
deve, então, subtrair o primeiro elemento de A do último de B, acumulando o valor, subtrair o segundo 
elemento de A do penúltimo de B, acumulando o valor e assim por diante. Ao final, mostre o resultado 
de todas as subtrações realizadas.*/
int main(){
    int i,j,A[5],B[5],acumulacao=0;
    j=4;
    for (i=0;i<5;i++){
        printf("Digite o %d numero de A:",i+1);
        scanf("%d",&A[i]);
        printf("\n");
        printf("Digite o %d numero de B:",j+1);
        scanf("%d",&B[j]);
        printf("\n");
        j--;
    }
    j=4;
    for (i=0;i<5;i++){
        printf("Resultado da %d subtracao: %d\n",i+1,A[i]-B[j]);
        acumulacao+=A[i]-B[j];
        j--;
    }
    printf("\nO resultado da acumulacao de todas as subtracoes realizadas: %d\n",acumulacao);
    return 0;
}