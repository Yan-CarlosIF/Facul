#include <stdio.h>

int main(){
	float a,r;
	printf("Valor do raio: ");
	scanf("%f", &r);
	
	a=3.14*(r*r);
	
	printf("Area: %f",a);
	return 0;
}
