#include <stdio.h>
#include <string.h>
#define prod 10

int main(){
    char nome_p[prod][30];
    int i,cod[prod];
    float preco[prod],n_preco[prod];
    for(i = 0; i < prod; i++){
        printf("Digite o nome do %d produto: \n",i+1);
        fflush(stdin);
        fgets(nome_p[i],sizeof(nome_p[i]),stdin);
        nome_p[i][strcspn(nome_p[i],"\n")]='\0';
        printf("Digite o codigo do %d produto: \n",i+1);
        scanf("%d",&cod[i]);
        printf("Digite o preco do %d produto: \n",i+1);
        scanf("%f",&preco[i]);
    }
    for (i = 0; i < prod; i++){
        if (cod[i]%2==0 && preco[i]>1000){
            n_preco[i]=preco[i]+(preco[i]*0.20);
            printf("\no produto: %s\ncodigo: %d\npreco: %.2f\nnovo preco: %.2f\n",nome_p[i],cod[i],preco[i],n_preco[i]);
        }
        else if (preco[i]>1000){
            n_preco[i]=preco[i]+(preco[i]*0.10);
            printf("\no produto: %s\ncodigo: %d\npreco: %.2f\nnovo preco: %.2f\n",nome_p[i],cod[i],preco[i],n_preco[i]);
        }
        else if (cod[i]%2==0){
            n_preco[i]=preco[i]+(preco[i]*0.15);
            printf("\no produto: %s\ncodigo: %d\npreco: %.2f\nnovo preco: %.2f\n",nome_p[i],cod[i],preco[i],n_preco[i]);
        }
        else{
            n_preco[i]=preco[i];
            printf("\no produto: %s\ncodigo: %d\npreco: %.2f\nnovo preco: %.2f\n",nome_p[i],cod[i],preco[i],n_preco[i]);
        }
    }
    return 0;
}