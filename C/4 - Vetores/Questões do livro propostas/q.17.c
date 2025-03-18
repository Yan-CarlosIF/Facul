#include <stdio.h>

int main(){
    int i,j;
    float vet1[10],vet2[10],vetr[20];
    printf("Digite 10 numeros:\n");
    for (i=0;i<10;i++){
        scanf("%f",&vet1[i]);
    }
    printf("\nDigite mais 10 numeros:\n");
    for (i = 0; i < 10; i++){
        scanf("%f",&vet2[i]);
    }
    for (i = 0; i < 10; i++){
        vetr[i]=vet1[i];
        vetr[i+10]=vet2[i];
    }
    for (i = 0; i < 20; i++){
        for (j = i; j < 20; j++){
            if (vetr[i] < vetr[j]){
                int aux = vetr[i];
                vetr[i] = vetr[j];
                vetr[j] = aux;
            }
        }
    }
    printf("\nDecrescente numeros:\n");
    for (i = 0; i < 20; i++){
        printf("%.1f\n",vetr[i]);
    }
    return 0;
}