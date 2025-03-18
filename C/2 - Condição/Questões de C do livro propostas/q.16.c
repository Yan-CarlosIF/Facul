#include <stdio.h>

int main(){
    int c;
    float pa,pn;
    printf("Digite o preco atual do produto:");
    scanf("%f",&pa);
    printf("Digite o codigo do produto:");
    scanf("%d",&c);

    if (pa<=30){
        pn=pa+(pa*0);
        printf("O produto de codigo %d nao possui desconto e seu novo preco eh:%.2f",c,pn);
    }
    else{
        if (pa<=100){
            pn=pa+(pa*0.10);
            printf("O produto de codigo %d nao possui desconto e seu novo preco eh:%.2f",c,pn);
        }
        else{
            pn=pa+(pa*0.15);
            printf("O produto de codigo %d nao possui desconto e seu novo preco eh:%.2f",c,pn);
        }
    }
    return 0;
}