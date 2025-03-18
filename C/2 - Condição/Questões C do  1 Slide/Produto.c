#include <stdio.h>

int main(){
	char nome[50];
	int q;
	float p,vt;
	printf("\nNome do produto: ");
	scanf("%s", &nome);
	printf("\nQuantidade do produto: ");
	scanf("%d", &q);
	printf("\npreco unitario do produto: ");
	scanf("%f", &p);
	
	vt=p*q;
	
	printf("\n\nProduto: %s",nome);
	printf("\nPreco Unitario: %f",p);
	printf("\nQuantidade adiquirida: %d",q);
	printf("\nValor Total a ser: %f",vt);
	return 0;
}
