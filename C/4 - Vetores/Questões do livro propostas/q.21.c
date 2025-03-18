#include <stdio.h>

int main(){
    int i,vetor[10],vetor2[10];
    printf("Digite 10 numeros inteiros:\n");
    for (i=0;i<10;i++){
        scanf("%d",&vetor[i]);
    }
    for (i=0;i<10;i++){
        if (vetor[i]==0){
            vetor2[i]=1;
            
        }
        else{
        vetor2[i]=vetor[i];
        }
    }
    printf("\nVetor 1:\n");
    for (i=0;i<10;i++){
        printf("%d\n",vetor[i]);
    }
    printf("\nVetor 2:\n");
    for (i=0;i<10;i++){
        printf("%d\n",vetor2[i]);
    }
    return 0;
}