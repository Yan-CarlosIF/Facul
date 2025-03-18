#include <stdio.h>

int main(){
	char nome;
	int idade;
	float altura,peso,imc;
	
	printf("insira seu nome: ");
	scanf("%s", &nome);
	printf("\ninsira sua idade: ");
	scanf("%d", &idade);
	printf("\ninsira sua altura: ");
	scanf("%f", &altura);
	printf("\ninsira seu peso: ");
	scanf("%f", &peso);
	
	imc=peso/(altura*altura);
	
	if(imc>40)
	{
		printf("\nSeu IMC e de:%f e voce esta classificado como Obeso Morbido!",imc);
	}
	else
	{
		if(imc>=30)
		{
			printf("\nSeu IMC e de:%f e voce esta classificado como Obeso!",imc);	
		}
		else
		{
			if(imc>=25)
			{
				printf("\nSeu IMC e de:%f e voce esta classificado como Sobrepeso!",imc);
			}
			else
			{
				if(imc>=20)
				{
					printf("\nSeu IMC e de:%f e voce esta classificado como Normal!",imc);
				}
				else
				{
					if(imc>=16)
					{
						printf("\nSeu IMC e de:%f e voce esta classificado como Subpeso!",imc);
					}
					else
					{
						printf("\nSeu IMC e de:%f e voce esta classificado como Subpeso Severo!",imc);
					}
				}
			}
		}
	}
}
