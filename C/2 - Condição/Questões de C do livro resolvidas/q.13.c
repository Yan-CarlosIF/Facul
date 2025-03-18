#include <stdio.h>
#include <stdlib.h>

int main(){
    int m;
    float s;
    printf("Menu do opcoes:\n1. Imposto\n2. Novo salario\n3. Classificacao\n");
    scanf("%d",&m);


    switch(m){
        case 1:
            printf("Qual o salario:");
            scanf("%f",&s);
            if(s>800){
                printf("O valor do imposto:%f",s*0.15);
            }
            else{
                if(s>=500){
                    printf("O valor do imposto:%f",s*0.10);
                }
                else{
                    printf("O valor do imposto:%f",s*0.05);
                }
            }
            break;
        case 2:
            printf("Qual o salario:");
            scanf("%f",&s);
            if(s>1500){
                printf("O novo salario e:%f",s+25);
            }
            else{
                if(s>=750){
                    printf("O novo salario e:%f",s+50);
                }
                else{
                    if(s>=450){
                        printf("O novo salario e:%f",s+75);
                    }
                    else{
                        printf("O novo salario e:%f",s+100);
                    }
                }
            }
            break;
        case 3:
            printf("Qual o salario:");
            scanf("%f",&s);
            if(s>700){
                printf("Voce e bem remunerado!");
            }
            else{
                printf("Voce e mal remunerado kkkkkkkkkkk\ntroca de emprego!");
            }
            break;
        default:printf("opcao invalida!");
    }
    return 0;
}
