#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,qp1,qp2,qp3,qp4,qp5;
    float vdi,vd1,vd3,vd6,vd9,vd12,vlj1,vlj2,vlj3,vlj4,vlj5;
    printf("Digite o valor da divida:");
    scanf("%f",&vdi);
    for (i = 1; i <=5; i++)
    {
        if (i==1)
        {
            vlj1=0;
            vd1=vdi+vlj1;
            qp1=1;
        }
        if (i==2)
        {
            vlj2=(vdi*0.10);
            vd3=vdi+vlj2;
            qp2=3;
        }
        if (i==3)
        {
            vlj3=(vdi*0.15);
            vd6=vdi+vlj3;
            qp3=6;
        }
        if (i==4)
        {
            vlj4=(vdi*0.20);
            vd9=vdi+vlj4;
            qp4=9;
        }
        if (i==5)
        {
            vlj5=(vdi*0.25);
            vd12=vdi+vlj5;
            qp5=12;
        }
    }
    printf("Valor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f",vd1,vlj1,qp1,vd1/(float)qp1);
    printf("\nValor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f",vd3,vlj2,qp2,vd3/(float)qp2);
    printf("\nValor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f",vd6,vlj3,qp3,vd6/(float)qp3);
    printf("\nValor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f",vd9,vlj4,qp4,vd9/(float)qp4);
    printf("\nValor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f",vd12,vlj5,qp5,vd12/(float)qp5);
    return 0;  
}