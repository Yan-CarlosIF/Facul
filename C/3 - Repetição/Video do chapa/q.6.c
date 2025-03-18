#include <stdio.h>

int main(){
    int num,cont25=0,cont50=0,cont75=0,cont100=0;
    do{
        printf("\nDigite um numero:");
        scanf("%d",&num);
        if (num>=0 && num<=25){
            cont25++;
        }
        else if (num<=50){
            cont50++;
        }
        else if (num<=75){
            cont75++;
        }
        else if (num<=100){
            cont100++;
        }
        printf("\nSe deseja terminar o codigo digite um numero menor que 0:");
        scanf("%d",&num);
    } while (num>0);
    printf("\nQuantidade do 1 intervalo: %d",cont25);
    printf("\nQuantidade do 2 intervalo: %d",cont50);
    printf("\nQuantidade do 3 intervalo: %d",cont75);
    printf("\nQuantidade do 4 intervalo: %d",cont100);
    return 0;
}