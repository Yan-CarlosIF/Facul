#include <stdio.h>

int main(){
	float v,r,h;
	printf("Escreva o Raio: ");
	scanf("%f", &r);
	printf("Escreva a altura: ");
	scanf("%f", &h);
	
	v=3.14*(r*r)*h;
	
	printf("Volume do cilindro: %f",v);
	return 0;
}
