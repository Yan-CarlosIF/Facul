#include <stdio.h>
#define tam 10

int main(){
    int i,vet1[tam],vet2[tam],vet3[tam];
    printf("Digite %d numeros:\n",tam);
    for (i=0;i<tam;i++){
        scanf("%d",&vet1[i]);
    }
    printf("\nDigite mais %d numeros:\n",tam);
    for (i=0;i<tam;i++){
        scanf("%d",&vet2[i]);
    }
    for (i = 0; i < tam; i++){
        vet3[i]=vet1[i]*vet2[i];
    }
    printf("\nMultiplicacao dos numeros de mesmo indice:\n");
    for (i = 0; i < tam; i++){
        printf("Indice:%d - Resultado:%d\n",i+1,vet3[i]);
    }
    return 0;
}