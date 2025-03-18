#include <stdio.h>
#include <stdlib.h>

int main(){
    float n1,n2,n3,m,ex;
    printf("Digite uma nota:");
    scanf("%f",&n1);
    printf("\nDigite outra nota:");
    scanf("%f",&n2);
    printf("\nDigite mais uma nota:");
    scanf("%f",&n3);

    m=(n1+n2+n3)/3;

    	if(m>=7){
        	printf("\nAprovado!, Sua Nota: %.1f",m);
        }
        else{
            if(m<3){
                printf("\nReprovado, Sua Nota: %.1f",m);
            }
            else{		
                printf("\nVoce ira fazer o exame final, sua nota e: %.1f",m);
                printf("\n\nDigite a nota do exame final:");
                scanf("%f",&ex);
                if(ex>=6){
                  	printf("\nAprovado!");
                }
                else{			
                    printf("\nVoce foi Reprovado");
                }
            }
        }
    return 0;
}
