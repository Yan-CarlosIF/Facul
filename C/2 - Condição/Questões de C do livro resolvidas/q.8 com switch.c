#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	float n1,n2;
	
	printf("O menu tem as seguintes Opcoes:\n\nPara somar dois numeros DIGITE 1\n\nPara saber a raiz quadrada de um numero DIGITE 2\n");
	scanf("%d",&i);
	
	switch (i)
	{
		case 1:
		{
			printf("\nDigite o primeiro numero:");
			scanf("%f",&n1);
			printf("\nDigite o segundo numero:");
			scanf("%f",&n2);
			printf("\nA soma de %.2f e %.2f e: %.2f",n1,n2,n1+n2);
			break;
		}
		case 2:
		{
			printf("\nDigite o numero que desejas saber a raiz quadrada:");
			scanf("%f",&n1);
			printf("\nA raiz quadrada de %.f e: %.2f",n1,sqrt(n1));
			break;
		}
			default: printf("Opcao invalida!");
	}
	
}
