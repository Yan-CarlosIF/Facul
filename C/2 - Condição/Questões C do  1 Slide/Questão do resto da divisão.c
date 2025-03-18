#include <stdio.h>

int main(){
	int x,y,z;
	printf("Numero 1: ");
	scanf("%d", &x);
	printf("numero 2: ");
	scanf("%d", &y);
	
	z=x%y;
	
	printf("Resto da divisao: %d",z);
	return 0;	
}
