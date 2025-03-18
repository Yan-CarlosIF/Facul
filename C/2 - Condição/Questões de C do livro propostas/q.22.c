#include <stdio.h>

int main(){
    int i;
    float p;
    printf("Digite sua idade:");
    scanf("%d",&i);
    printf("\nDigite seu peso:");
    scanf("%f",&p);

    if (i<20){
        if (p<=60){
            printf("Grupo de risco 9");
        }
        else if (p<=90){
            printf("Grupo de risco 8");
        }
        else{
            printf("Grupo de risco 7");
        }
    }
    else if (i<=50){
        if (p<=60){
            printf("Grupo de risco 6");
        }
        else if (p<=90){
            printf("Grupo de risco 5");
        }
        else{
            printf("Grupo de risco 4");
        }
    }
    else{
        if (p<=60){
            printf("Grupo de risco 3");
        }
        else if (p<=90){
            printf("Grupo de risco 2");
        }
        else{
            printf("Grupo de risco 1");
        }
    }
    return 0;
}