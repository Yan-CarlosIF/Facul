#include <stdio.h>
#include <stdlib.h>
/*
  1.2.3 check
  3.2.1 check
  2.1.3 check
  1.3.2 check
  2.3.1 check
  3.1.2 check
*/
int main(){
	float n1,n2,n3;
	printf("Digite o primeiro numero:");
	scanf("%f",&n1);
	printf("Digite o segundo numero:");
	scanf("%f",&n2);
	printf("Digite o terceiro numero:");
	scanf("%f",&n3);
	
	if(n1<n2 && n2<n3){
		printf("A ordem e de: %.2f %.2f %.2f",n1,n2,n3);	
	}
	else{
	 	if(n3<n2 && n2<n1){
	 		printf("A ordem e de: %.2f %.2f %.2f",n3,n2,n1);
		}
		else{
			if(n3<n1 && n1<n2){
				printf("A ordem e de: %.2f %.2f %.2f",n3,n1,n2);
			}
			else{
				if(n2<n1 && n1<n3){
					printf("A ordem e de: %.2f %.2f %.2f",n2,n1,n3);
				}
				else{
					if(n1<n3 && n3<n2){
						printf("A ordem e de: %.2f %.2f %.2f",n1,n3,n2);
					}
					else{
						if(n2<n3 && n3<n1){
							printf("A ordem e de: %.2f %.2f %.2f",n2,n3,n1);
						}
						else{
							printf("Os numeros sao todos iguais!");
						}
					}
				}
			}
		}
	}
	return 0;
}
