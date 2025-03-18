#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Faça um programa que receba o total das vendas de cada vendedor de uma loja e armazene-as em um vetor. 
Receba também o percentual de comissão a que cada vendedor tem direito e armazene-os em outro vetor. 
Receba os nomes desses vendedores e armazene-os em um terceiro vetor. Existem apenas dez vendedores na 
loja. Calcule e mostre: 
 ■ um relatório com os nomes dos vendedores e os valores a receber referentes à comissão; 

 ■ o total das vendas de todos os vendedores; 

 ■ o maior valor a receber e o nome de quem o receberá; 

 ■ o menor valor a receber e o nome de quem o receberá. */
#define vend 10
int main(){
    int i;
    float total_vendas[vend],p_comissao[vend],valor_comi,valor_maior,valor_menor;
    char nomes[vend][50],nome_maior[50],nome_menor[50];
    for (i = 0; i < vend; i++){
        printf("Insira o total de vendas do vendedor %d:",i+1);
        scanf("%f",&total_vendas[i]);
    }
    for (i = 0; i < vend; i++){
        printf("Insira o percentual de comissao a que o vendedor %d tem direito:",i+1);
        scanf("%f",&p_comissao[i]);
    }
    for (i = 0; i < vend; i++){
        printf("Insira o nome vendedor %d\n:",i+1);
        fflush(stdin);
        fgets(nomes[i],sizeof(nomes[i]),stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }
    printf("\nRelatorio das comissoes:\n\n");
    for (i = 0; i < vend; i++){
        valor_comi=total_vendas[i]*(p_comissao[i]/100);
        printf("O vendedor %s tem direito a uma comissao de %.1f%% o valor referente eh %.2f\n",nomes[i],p_comissao[i],valor_comi);
        if (i==0){
            valor_maior=valor_comi;
            strcpy(nome_maior,nomes[i]);
            valor_menor=valor_comi;
            strcpy(nome_menor,nomes[i]);
        }
        if (valor_maior<valor_comi){
            valor_maior=valor_comi;
            strcpy(nome_maior,nomes[i]);
        }
        if (valor_menor>valor_comi){
            valor_menor=valor_comi;
            strcpy(nome_menor,nomes[i]);
        }  
    }
    printf("\nRelatorio do total das vendas:\n\n");
    for (i = 0; i < vend; i++){
        printf("O total das vendas do vendedor %d de nome %s: %.2f\n",i+1,nomes[i],total_vendas[i]);
    }
    printf("\nO maior valor recebido eh %.2f do vendedor %s\n",valor_maior,nome_maior);
    printf("\nO menor valor recebido eh %.2f do vendedor %s\n",valor_menor,nome_menor);
    system("PAUSE");
    return 0;
}