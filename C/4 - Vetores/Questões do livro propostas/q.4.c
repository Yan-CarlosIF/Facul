#include <stdio.h>

int main(){
    int i,vet[15];
    
    printf("Digite 15 numeros:\n");
    for (i = 0; i < 15; i++) {
        scanf("%d",&vet[i]);
    }
    for (i = 0; i < 15; i++) {
        if (vet[i]==30) {
            printf("%d na posicao %d\n",vet[i],i+1);
        }
    }
    return 0;
}