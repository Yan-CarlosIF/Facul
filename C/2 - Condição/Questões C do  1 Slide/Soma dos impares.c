#include <stdio.h>

int main(){
    int i,x,y,soma=0;
    printf("Digite um numero:");
    scanf("%d",&x);
    printf("Digite outro numero:");
    scanf("%d",&y);
    if (y>x){
        for (i=x+1;i<y;i++){
            if (i%2!=0){
                soma+=i;
            }
        }
        printf("\nA soma dos impares: %d\n",soma);
    }
    else if (x>y){
         for (i=x-1;i>y;i--){
            if (i%2!=0){
                soma+=i;
            }
        }
        printf("\nA soma dos impares: %d\n",soma);
    }
    else{
        printf("Os numeros são iguais");
    }
    return 0;
}