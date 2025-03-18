#include <stdio.h>
#include <stdlib.h>

int main(){
	int h1,h2,m1,m2;
	
	printf("Digite a hora do inicio:");
	scanf("%d",&h1);
	printf("Digite os minutos do inicio:");
	scanf("%d",&m1);
	printf("Digite a hora do final:");
	scanf("%d",&h2);
	printf("Digite os minutos do final:");
	scanf("%d",&m2);
	
	if(m1>m2){
		m2 += 60;
		h2 -= 1;
	}
	if(h1>h2){
		h2 += 24;
	}
	printf("\nO jogo durou %d hora(s) e %d minuto(s)",h2-h1,m2-m1);
	return 0;
}
