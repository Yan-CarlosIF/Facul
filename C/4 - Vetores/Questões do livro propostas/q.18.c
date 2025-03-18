#include <stdio.h>

int main(){
    int i,vetor[15],maior,menor,contma=0,contme=0;
    printf("Digite 15 numeros:\n");
    for(i=0;i<15;i++){
        scanf("%d",&vetor[i]);
    }
    for (i = 0; i < 15; i++){
        if (i==0){
            maior=vetor[i];
            menor=vetor[i];
        }
        if (maior<vetor[i]){
            maior=vetor[i];
            }
        if (menor>vetor[i]){
            menor=vetor[i];
        }
    }
    for (i = 0; i < 15; i++){
        if (maior==vetor[i]){
            contma++;
            
        }
        if (menor==vetor[i]){
            contme++;
        }
    }
    int posimaior[contma],posimenor[contme];
    printf("\nO maior valor do vetor eh %d e aparece na(s) posicao(s): ",maior);
    for (i = 0; i < 15; i++){
        if (maior==vetor[i]){
            posimaior[i]=i+1;
            printf("%d ",posimaior[i]);
        }
    }
    printf("\nO menor valor do vetor eh %d e aparece na(s) posicao(s): ",menor);
    for (i = 0; i < 15; i++){
        if (menor==vetor[i]){
            posimenor[i]=i+1;
            printf("%d ",posimenor[i]);
        }
    }
    return 0;
}