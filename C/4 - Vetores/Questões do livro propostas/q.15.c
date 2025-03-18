#include <stdio.h>
#include <string.h>
#define clientes 8

int main(){
    int i,dvd[clientes],cont_gratis;
    char nome[clientes][50];
    for(i=0;i<clientes;i++){
        printf("Digite o nome do %d cliente:",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome[i]),stdin);
        nome[i][strcspn(nome[i],"\n")]='\0';
        printf("Digite a quantidade de DVDs locados por %s:",nome[i]);
        scanf("%d",&dvd[i]);
    }
    printf("\n");
    for(i=0;i<clientes;i++){
        cont_gratis=0;
        cont_gratis=dvd[i]/10;
        printf("O cliente %s tem direito a %d locacao(s) gratis!\n",nome[i],cont_gratis);
    }
    return 0;
}