#include <stdio.h>

int main(){
    int i,vet[5],soma=0;
    for(i=0;i<5;i++) {
        printf("Digite o %d numero: ",i+1);
        scanf("%d",&vet[i]);
        soma+=vet[i];
    }
    printf("Os numeros digitados foram:");
    for (i=0;i<5;i++) {
        printf(" %d",vet[i]);
    }
    printf(" = %d",soma);
    return 0;
}