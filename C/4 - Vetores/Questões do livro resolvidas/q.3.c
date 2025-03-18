#include <stdio.h>

int main(){
    int i,j,v1[10],v2[10],v3[20];
    j=0;
    for(i=0;i<10;i++){
        printf("Digite numero do 1 vetor:\n");
        scanf("%d",&v1[i]);
        v3[j]=v1[i];
        j++;
        printf("Digite numero do 2 vetor:\n");
        scanf("%d",&v2[i]);
        v3[j]=v2[i];
        j++;
    }
    printf("\nIntercalacao dos vetores:\n");
    for (j = 0; j < 20; j++){
        printf("\n%d",v3[j]);
    }
    return 0;
}