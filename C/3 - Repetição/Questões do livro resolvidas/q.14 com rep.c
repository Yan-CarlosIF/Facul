#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,qp=1;
    float vdi,vd,vlj=0;
    printf("Digite o valor da divida:");
    scanf("%f",&vdi);
    vd=0;
    qp+=2;
    for (i = 1; i<=4; i++)
    {
        vlj+=10/(float)100;
        vd=vdi+(vdi*vlj);
        printf("Valor da divida %.2f|Valor do juros %.2f|Quantidade de parcelas %d|Valor da parcela %.2f\n",vd,vlj,qp,vd/(float)qp);
        qp+=3;
        vlj+=(5/(float)100)-0.10;
    }
    return 0;
}