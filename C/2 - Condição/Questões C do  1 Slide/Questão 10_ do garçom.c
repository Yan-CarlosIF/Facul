#include <stdio.h>

int main(){
	float valor;float acrescimo;float valort;
	printf("Qual o valor da conta?: ");
	scanf("%f", &valor);
	
	acrescimo = valor/10;
	printf("\nAcrescimo do garcom: %.f",acrescimo);
	
	
	valort= valor+acrescimo;
	printf("\n\nValor com acrescimo: %.f",valort);
	return 0;
}
