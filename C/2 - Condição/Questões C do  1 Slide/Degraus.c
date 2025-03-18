#include <stdio.h>

int main(){
	float de,al;
	
	printf("Altura do degrau em metros:");
	scanf("%f", &de);
	
	printf("\nQual altura o Usuário deseja alcançar em metros:");
	scanf("%f", &al);
	
	printf("\nEle deverá subir ");printf("%.f",al/de);printf(" degraus para alcançar a altura desejada.");		
	return 0;
}
