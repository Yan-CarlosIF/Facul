#include <stdio.h>
/*Faça um programa que leia um vetor com quinze posições para números inteiros. Depois da leitura, di
vida todos os seus elementos pelo maior valor do vetor. Mostre o vetor após os cálculos. */
#define tam 15
int main(){
    int i;
    float vetor[tam],maior;
    printf("Digite %d numeros:\n",tam);
    for (i = 0; i < tam; i++){
        scanf("%f",&vetor[i]);
        if (i==0){
            maior=vetor[i];
        }
        if (maior<vetor[i]){
            maior=vetor[i];
        }
    }
    printf("\nOs numeros dividos por %.2f:\n",maior);
    for (i=0;i<tam;i++){
        printf("%.2f / %.2f = %.2f\n",vetor[i],maior,vetor[i]/maior);
    }
    return 0;
}