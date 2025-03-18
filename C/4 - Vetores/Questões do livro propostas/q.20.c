#include <stdio.h>

int main(){
    int i,vetor[10];
    printf("Digite 10 numeros inteiros:\n");
    for (i=0;i<10;i++){
        scanf("%d",&vetor[i]);
    }
    printf("\nNumeros positivos:\n");
    for (i=0;i<10;i++){
        if (vetor[i]>0){
           printf("%d\n",vetor[i]); 
        }  
    }
    return 0;
}