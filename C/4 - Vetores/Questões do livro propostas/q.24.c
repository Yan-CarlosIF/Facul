#include <stdio.h>
/*Faça um programa que leia um vetor com quinze posições para números inteiros. Crie, a seguir, um vetor 
resultante que contenha todos os números primos do vetor digitado. Escreva o vetor resultante. */
int main(){
    int i,k=0,vet[15],contdiv,contp=15,vetr[15];
    printf("Digite 15 numeros:\n");
    for (i = 0; i < 15;i++){
        scanf("%d",&vet[i]);
        contdiv=0;
        for(int j=1;j<=vet[i];j++){
            if (vet[i]%j==0){
                contdiv++;
            }
        }
        if (contdiv==2){
            vetr[k]=vet[i];
            k++;
        }
        else{
            contp--;
        }
    }
    printf("\nNumeros primos:\n");
    for (i = 0; i < contp; i++){
        printf("%d\n",vetr[i]);
    }
    return 0;
}