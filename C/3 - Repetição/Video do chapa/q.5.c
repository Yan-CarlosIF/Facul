#include <stdio.h>

int main(){
    int i=0,cont_p=0,cont_n=0;
    float num,soma=0;
    do{
        printf("\nDigite um numero, ira parar quando digitar 0:\n");
        scanf("%f",&num);
        if (num!=0){
        soma+=num;
        if (num>0){
            cont_p++;
        }
        else if (num<0){
            cont_n++;
        }
        else{
            
        }
        i++;
        }
    } while(num!=0);
    float media=soma/i;
    printf("\nMedia: %.1f",media);
    printf("\nQuantidade de positivos: %d\nPorcetagem de positivos: %.1f%%",cont_p,(cont_p/(float)i)*100);
    printf("\nQuantidade de negativos: %d\nPorcetagem de negativos: %.1f%%",cont_n,(cont_n/(float)i)*100);
    return 0;
}