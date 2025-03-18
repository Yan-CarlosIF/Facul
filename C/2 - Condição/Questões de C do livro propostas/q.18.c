#include <stdio.h>

int main(){
    int id;
    printf("Digite sua idade:");
    scanf("%d",&id);

    if (id<18){
        printf("\nVoce tem %d anos e eh menor de idade",id);
    }
    else{
        printf("\nVoce tem %d anos e eh maior de idade",id);
    }
    return 0;
}