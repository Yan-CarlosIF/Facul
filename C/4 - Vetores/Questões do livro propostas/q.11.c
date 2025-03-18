#include <stdio.h>
#define tam 10

int main(){
    int i,vet[tam],par[tam],imp[tam],contp=0,conti=0;
    printf("Digite 10 numeros inteiros:\n");
    for (i=0; i < tam;i++){
        scanf("%d",&vet[i]);
    }
    for (i = 0; i < tam; i++){
        if (vet[i]%2==0){
            par[contp]=vet[i];
            contp++;
        }
        else{
            imp[conti]=vet[i];
            conti++;
        }
    }
    printf("\nPares:");
    for (i = 0; i < contp; i++){
        printf("%d ",par[i]);
    }
    printf("\nImpares:");
    for (i = 0; i < conti; i++){
        printf("%d ",imp[i]);
    }
    
    return 0;
}