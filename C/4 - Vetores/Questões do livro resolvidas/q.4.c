#include <stdio.h>

int main(){
    int i,num[8],pos[8],neg[8];
    printf("Digite 8 numeros inteiros:\n");
    for (i = 0; i < 8; i++){
        scanf("%d",&num[i]);
    }
    printf("\nNumeros positivos: ");
    int j=0;
    for (i = 0; i < 8; i++){
        if (num[j]>=0){
            pos[i]=num[j];
            printf("%d ",pos[i]);
        }
        j++;
    }
    printf("\nNumeros negativos: ");
    j=0;
    for (i = 0; i < 8; i++){
        if (num[j]<0){
            neg[i]=num[j];
            printf("%d ",neg[i]);
        }
        j++;
    }
    return 0;
}