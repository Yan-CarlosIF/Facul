#include <stdio.h>

int main(){
    int i,vet[7];
    printf("Digite 7 numeros inteiros:\n");
    for(i = 0 ; i < 7; i++){
        scanf("%d",&vet[i]);
    }
    printf("\nOs numeros multiplos de 2:\n");
    for (i = 0; i < 7; i++){
        if(vet[i]%2 == 0){
            printf("%d ",vet[i]);
        }
    }
    printf("\nOs numeros multiplos de 3:\n");
    for (i = 0; i < 7; i++){
        if(vet[i]%3 == 0){
            printf("%d ",vet[i]);
        }
    }
    printf("\nOs numeros multiplos de 2 e 3:\n");
    for (i = 0; i < 7; i++){
        if(vet[i]%2 == 0 && vet[i]%3 == 0){
            printf("%d ",vet[i]);
        }
    }
    printf("\nOs numeros que nao sao multiplos de 2 e 3:\n");
    for (i = 0; i < 7; i++){
        if(vet[i]%2 != 0 && vet[i]%3 != 0){
            printf("%d ",vet[i]);
        }
    }
    return 0;
}