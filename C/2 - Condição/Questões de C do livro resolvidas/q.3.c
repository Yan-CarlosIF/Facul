#include <stdio.h>
#include <stdlib.h>

int main()
{
	float n1,n2;
	printf("Digite um numero:");
	scanf("%f",&n1);
	printf("Digite outro numero:");
	scanf("%f",&n2);
	
	if(n1>n2){
	printf("o maior numero entre eles e: %f",n1);
	}
	else{
		if(n2>n1){
		printf("o maior numero entre eles e: %f",n2);
		}
		else{
			if(n1==n2){
				printf("Eles sao iguais");
			}
		}
	}
	return 0;
}
