#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	float a,b,c;
	
	printf("Digite o numero de A:");
	scanf("%f",&a);
	printf("\nDigite o numero de B:");
	scanf("%f",&b);
	printf("\nDigite o numero de C:");
	scanf("%f",&c);
	printf("\nDigite um valor de 1,2 ou 3 para I:");
	scanf("%d",&i);
	
	switch(i){
		case 1:
			if(a<b && a<c){
				if(b<c){
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",a,b,c);
				}
				else{
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",a,c,b);
				}
			}
			if(b<a && b<c){
				if(a<c){
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",b,a,c);
				}
				else{
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",b,c,a);
				}
			}
			if(c<a && c<b){
				if(a<b){
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",c,a,b);
				}
				else{
					printf("a ordem crescente dos numeros e: %.2f %.2f %.2f",c,b,a);
				}
			}
			break;
		case 2:
			if(a<b && a<c){
				if(b<c){
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",c,b,a);
				}
				else{
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",b,c,a);
				}
			}
			if(b<a && b<c){
				if(a<c){
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",c,a,b);
				}
				else{
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",a,c,b);
				}
			}
			if(c<a && c<b){
				if(a<b){
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",b,a,c);
				}
				else{
					printf("a ordem decrescente dos numeros e: %.2f %.2f %.2f",a,b,c);
				}
			}
			break;
		case 3:
			if(b>c && b>a){
				printf("O maior numero sendo o do meio: %.2f %.2f %.2f",a,b,c);	
			}
			else{
				if(a>c && a>b){
					printf("A ordem com o maior numero sendo o do meio: %.2f %.2f %.2f",b,a,c);
				}
				else{
					printf("A ordem com o maior numero sendo o do meio: %.2f %.2f %.2f",b,c,a);
				}
			}
			break;
		default:printf("\n\nO numero escolhido e invalido");	
	}
	return 0;
}
