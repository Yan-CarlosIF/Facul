#include <stdio.h>

int main(){
	int an,aa;
	
	printf("Digite seu ano de nascimento:");
	scanf("%d", &an);
	
	printf("\nDigite o ano atual:");
	scanf("%d", &aa);
	
	printf("\nSua Idade: %d",aa-an);
	printf("\n\nSua idade em 2050: %d",2050-an);
	return 0;
}
