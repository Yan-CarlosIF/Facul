#include <stdio.h>
/*Faça um programa que leia um vetor A de dez posições. Em seguida, compacte o vetor, retirando os 
valores nulos e negativos. Armazene esse resultado no vetor B. Mostre o vetor B. (lembre-se: o vetor B 
pode não ser completamente preenchido.)*/
int main(){ 
    int i,j=0,vetorA[10],contm0=10,vetorB[contm0];
    printf("Digite 10 numeros:\n");
    for (i = 0; i < 10; i++){
        scanf("%d",&vetorA[i]);
        if (vetorA[i]<=0){
            contm0--;
        }
        else{
            vetorB[j]=vetorA[i];
            j++;
        }
    }
    printf("\nVetor B:\n");
    for (i = 0; i < contm0; i++){
        printf("%d\n",vetorB[i]);
    }
    return 0;
}