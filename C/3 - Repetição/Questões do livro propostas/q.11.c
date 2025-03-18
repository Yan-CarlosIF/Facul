#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qp;
    float v_carro,acres=3,v_acres,p_final;

    printf("Digite o valor do carro:");
    scanf("%f",&v_carro);
    for (qp = 6;qp<=60;qp+=6)
    {
        v_acres=v_carro*(acres/100);
        p_final=v_carro+v_acres;
        printf("\nQuantidade de parcelas: %d - Valor da parcela: %.2f",qp,p_final/qp);
        printf("\nPreco final: %.2f",p_final);
        printf("\nPreco final a vista: %.2f",v_carro-(v_carro/5));
        acres+=3;
    }
    return 0;
}