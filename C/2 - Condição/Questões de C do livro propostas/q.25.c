#include <stdio.h>

int main()
{
    float hf,m,he,h;
    printf("Digite o numero de horas extras:");
    scanf("%f",&he);
    printf("Digite o numero de horas faltadas:");
    scanf("%f",&hf);

    h=he-((hf)*2/3);
    m=h*60;
    
    if (m>=2400){
        printf("o tempo em minutos %f e seu premio eh de 500,00 reais!",m);
    }
    else{
        if (m>1800){
            printf("o tempo em minutos %f e seu premio eh de 400,00 reais!",m);
        }
        else{
            if (m>=1200){
                printf("o tempo em minutos %f e seu premio eh de 300,00 reais!",m);
            }
            else{
                if (m>=600){
                    printf("o tempo em minutos %f e seu premio eh de 200,00 reais!",m);
                }
                else{
                    printf("o tempo em minutos %f e seu premio eh de 100,00 reais!",m);
                }
            }
        }
    }
    return 0;   
}