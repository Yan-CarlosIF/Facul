#include <stdio.h>

int main(){
    int cp,qc;
    float pu,pt,vd,pf;
    do{
    printf("Digite o codigo do produto de 1 a 40:");
    scanf("%d",&cp);
    } while(cp>=40);
    printf("\nDigite a quantidade comprada do produto:");
    scanf("%d",&qc);
    
    if (cp<=10){
        pu=10;
    }
    else{
        if (cp<=20){
            pu=15;
        }
        else{
            if (cp<=30){
                pu=20;
            }
            else{
                pu=30;
            }
        }
    }
    pt=pu*qc;
    if (pt<=250){
        vd=pt*0.05;
    }
    else{
        if (pt<=500){
            vd=pt*0.10;
        }
        else{
            vd=pt*0.15;
        }
    }
    pf=pt-vd;
    printf("o preco final da nota %.2f",pf);
    return 0;
}