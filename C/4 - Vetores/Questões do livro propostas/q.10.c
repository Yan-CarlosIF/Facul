#include <stdio.h>

#define v1 10
#define v2 5                                
int main(){
    int i,j,vet1[v1],vet2[v2],somavet2=0,vet_r1[v1],cont;
    printf("Digite 15 numeros inteiros:\n");
    for (i=0;i < v1;i++){
        scanf("%d",&vet1[i]);
    }
    printf("\nDigite 5 numeros inteiros:\n");
    for (i=0;i < v2;i++){
        scanf("%d",&vet2[i]);
        somavet2+=vet2[i];
    }
    printf("\n");
    for (i = 0; i < v1; i++){
        if (vet1[i]%2==0){
            vet_r1[i]=vet1[i]+somavet2;
            printf("soma do numero %d do vetor 1 com todos do vetor 2: %d\n",vet1[i],vet_r1[i]);
        }
    }
    for (i=0; i < v1; i++){
        cont=0;
        for (j=0; j < v2; j++){
            if (vet1[i]%vet2[j]==0){
                cont++;
            }
        }
        printf("A quantidade de divisores de %d eh %d\n",vet1[i],cont);
    }
    
    return 0;
}