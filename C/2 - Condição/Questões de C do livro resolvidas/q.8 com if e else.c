#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	float n1,n2;
	double raiz,teste;
	do{
	printf("O menu tem as seguintes Opcoes:\n\nPara somar dois numeros DIGITE 1\n\nPara saber a raiz quadrada de um numero DIGITE 2\n");
	scanf("%d",&i);
	} while(i != 1 && i != 2);
	if(i==1){
		printf("\nDigite o primeiro numero:");
		scanf("%f",&n1);
		printf("\nDigite o segundo numero:");
		scanf("%f",&n2);
		printf("\nO resultado da soma e: %.1f",n1+n2);
	}
	else if (i==2){
		printf("\nDigite o numero que deseja saber a raiz quadrada:");
		scanf("%f",&n1);
		raiz=sqrt(n1);
		teste = modf(raiz, &raiz);
		if (teste == 0.0)
		{
			printf("\nO resultado da raiz quadrada e: %.lf",raiz);
		}
		else{
		printf("Nao possui raiz exata");
		}
	}
	return 0;
}
