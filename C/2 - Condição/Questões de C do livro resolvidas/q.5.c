#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,k;
	float n1,n2,n3,n4;
	printf("Digite os numeros abaixo em ordem crescente");
	do{
		printf("\n\nDigite o primeiro numero em ordem crescente:");
		scanf("%f",&n1);
		i=n1;
		printf("\nDigite o segundo numero em ordem crescente:");
		scanf("%f",&n2);
		j=n2;
		printf("\nDigite o terceiro numero em ordem crescente:");
		scanf("%f",&n3);
		k=n3;
		printf("\nDigite o mais um numero:");
		scanf("%f",&n4);
	} while(j<i || k<j || n4==n3 || n4 == n1 || n4 == n2);
	
	if(n4<n1){
		printf("\nordem descrescente dos numeros digitados: %.2f %.2f %.2f %.2f",n3,n2,n1,n4);
	}
	else{
		if(n4<n2 && n4>n1){
				printf("\nordem descrescente dos numeros digitados: %.2f %.2f %.2f %.2f",n3,n2,n4,n1);
		}
		else{
			if(n4<n3){
				printf("\nordem descrescente dos numeros digitados: %.2f %.2f %.2f %.2f",n3,n4,n2,n1);
			}
			else{
				printf("\nordem descrescente dos numeros digitados: %.2f %.2f %.2f %.2f",n4,n3,n2,n1);
			}
		}	
	}
	return 0;
}
