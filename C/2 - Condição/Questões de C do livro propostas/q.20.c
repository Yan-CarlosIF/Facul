#include <stdio.h>

int main(){
    int i;
    printf("Voce nadador, digite sua idade:");
    scanf("%d",&i);

    if (i>30){
        printf("\nVoce esta na categoria Senior");
    }
    else{
        if (i>=16){
            printf("\nVoce esta na categoria Adulto");
        }
        else{
            if (i>=1){
                printf("\nVoce esta na categoria Adolescente");
            }
            else{
                if (i>=8){
                    printf("\nVoce esta na categoria Juvenil");
                }
                else{
                    if (i>=5){
                        printf("\nVoce esta na categoria Infantil");
                    }
                    else{
                        printf("\nTu eh mto novo pra competir");
                    }
                }
            }
        }
    }
    return 0;
}