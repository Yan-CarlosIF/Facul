#include <stdio.h>

int main(){
    int c;
    float p;
    printf("Digite o preco do produto:");
    scanf("%f",&p);
    printf("\nDigite o codigo do produto:");
    scanf("%d",&c);

    if (c==1){
        printf("\nO produto de codigo %d e de preco %.2f vem do Sul",c,p);
    }
    else{
        if (c==2){
            printf("\nO produto de codigo %d e de preco %.2f vem do Norte",c,p);
        }
        else{
            if (c==3){
                printf("\nO produto de codigo %d e de preco %.2f vem do Leste",c,p);
            }
            else{
                if (c==4){
                    printf("\nO produto de codigo %d e de preco %.2f vem do Oeste",c,p);
                }
                else{
                    if (c==5 || c==6){
                        printf("\nO produto de codigo %d e de preco %.2f vem do Nordeste",c,p);
                    }
                    else{
                        if (c==7 || c==8 || c==9){
                            printf("\nO produto de codigo %d e de preco %.2f vem do Sudeste",c,p);
                        }
                        else{
                            if (c<=20){
                                printf("\nO produto de codigo %d e de preco %.2f vem do Centro-oeste",c,p);
                            }
                            else{
                                if (c<=30){
                                    printf("\nO produto de codigo %d e de preco %.2f vem do Nordeste",c,p);
                                }
                                else{
                                    printf("Codigo de origem do produto eh invalido!");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}