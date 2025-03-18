#include <stdio.h>
#include <string.h>
#define prod 5
int main(){
    int i,cont_p50=0,cont_p100=0;
    char nome[prod][30];
    float preco[prod],media_p100=0;
    for(i=0;i<prod;i++){
        printf("Digite o nome do produto %d:",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome[i]),stdin);
        printf("Digite o preco do(a) %s:",nome[i]);
        scanf("%f",&preco[i]);
        if(preco[i]<50){
            cont_p50++;
        }
        if(preco[i]>100){
            cont_p100++;
            media_p100+=preco[i];
        } 
    }
    printf("\nA Quantidade de produtos com preco inferior a 50R$:%d\n",cont_p50);
    printf("\nO nome dos produtos com preco entre 50R$ e 100R$:\n");
    for (i = 0; i < prod; i++){
        if(preco[i]>50 && preco[i]<100){
            printf("%s",nome[i]);
        }
    }
    printf("\nA media dos precos dos produtos com preco superior a 100R$: %.1f\n",media_p100/cont_p100);
    return 0;
}
