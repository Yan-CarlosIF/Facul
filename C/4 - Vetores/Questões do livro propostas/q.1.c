#include <stdio.h>

int main(){
    int i,vet[6],contpar=0,contimp=0;
    printf("Digite 6 numeros inteiros:\n");
    for (i = 0; i < 6; i++){
        scanf("%d",&vet[i]);
    }
    printf("\nOs numeros pares:\n");
    for (i = 0; i < 6; i++){
        if(vet[i]%2 == 0){
            printf("%d ",vet[i]);
            contpar++;
        }
    }
     if (contpar==0){
            printf("\nentre os 6 numeros digitados, nao exitem numeros pares\n\n");
        }
        else{
            printf("\nContagem de numeros pares: %d\n\n",contpar);
        }
        printf("Os numeros impares:\n");
    for(i = 0; i < 6; i++){
        if (vet[i]%2 != 0){
            printf("%d ",vet[i]);
            contimp++;
        }
    }
    if (contimp==0){
            printf("\nentre os 6 numeros digitados, nao exitem numeros impares\n\n");
        }
        else{
            printf("\nContagem de numeros impares: %d\n",contimp);
        }
    return 0;
}