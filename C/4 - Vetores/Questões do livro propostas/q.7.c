#include <stdio.h>
/*Faça um programa que preencha um vetor com dez números reais, calcule e mostre a quantidade de números 
negativos e a soma dos números positivos desse vetor. */
int main(){
    float vet[10],somaposi=0;
    int i,contneg=0;
    for (i = 0; i < 10; i++){
        printf("Digite um numero:\n");
        scanf("%f",&vet[i]);
        if (vet[i]<0){
            contneg++;
        }
        else{
            somaposi+=vet[i];
        }  
    }
    printf("Quantidade de numeros negativos: %d\n",contneg);
    printf("Soma dos numeros positivos: %.2f\n",somaposi);
    return 0;
}