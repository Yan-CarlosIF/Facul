#include <stdio.h>
#include <stdlib.h>
#define p1 2
#define p2 3
#define p3 5
int main()
{
    float tl,as,ef,mp;

    printf("Digite a nota do trabalho de laboratorio:");
    scanf("%f",&tl);
    printf("\nDigite a nota da avaliacaoo semestral:");
    scanf("%f",&as);
    printf("\nDigite a nota do exame final:");
    scanf("%f",&ef);

    mp=((tl*p1)+(as*p2)+(ef*p3))/(p1+p2+p3);

    if(mp>=8){
    printf("sua nota e:%.2f e seu conceito da nota e A",mp);
    }
    	else{
        	if(mp>=7){
        	printf("sua nota e:%.2f e seu conceito da nota e B",mp);
        	}
        	else{
            	if(mp>=6)
            	printf("sua nota e:%.2f e seu conceito da nota e C",mp);
				else{
					if(mp>=5){
						printf("sua nota e:%.2f e seu conceito da nota e D",mp);
					}
					else{
						printf("sua nota e:%.2f e seu conceito da nota e E",mp);
					}
				}
        	}
    	}
    return 0;
}
