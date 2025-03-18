#include <stdio.h>
#include <stdlib.h>

int main()
{
	float sm,ht,het,vhet,vht,sdm,sb,sl,apd;
	int df;
	printf("Digite o valor do salario minimo:");
	scanf("%f",&sm);
	printf("\nDigite o numero de horas trabalhadas:");
	scanf("%f",&ht);
	printf("\nDigite o numero de dependentes do funcionario:");
	scanf("%d",&df);
	printf("\nDigite a quantidade de horas extras:");
	scanf("%f",&het);
	vht=sm/5;
	sdm=ht*vht;
	apd=df*32;
	vhet=het*(vht+(vht/2));
	sb=sdm+apd+vhet;
	
	if(sb>500){
		sl=sb-(sb*0.20);
	}
	else if(sb>=200){
		sl=sb-(sb*0.10);
	}
	else{
		sl=sb;
	}
	if(sl>350){
		printf("O salario a receber e de:%.2f",sl+50);
	}
	else{
		printf("O salario a receber e de:%.2f",sl+100);
	}
	return 0;
}
