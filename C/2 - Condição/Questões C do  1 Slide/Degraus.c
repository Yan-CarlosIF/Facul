#include <stdio.h>

int main(){
	float de,al;
	
	printf("Altura do degrau em metros:");
	scanf("%f", &de);
	
	printf("\nQual altura o Usu�rio deseja alcan�ar em metros:");
	scanf("%f", &al);
	
	printf("\nEle dever� subir ");printf("%.f",al/de);printf(" degraus para alcan�ar a altura desejada.");		
	return 0;
}
