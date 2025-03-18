#include <stdio.h>

int main(){
    int i,num[10];
    printf("Digite 10 numeros:\n");
    for (i = 0; i < 10; i++){
        scanf("%d",&num[i]);
    }
    printf("O numero e a sua metade:\n");
    for (i = 0; i < 10; i++){
        printf("%d - %.1f\n",num[i],num[i]/(float)2);
    }
    return 0;
}