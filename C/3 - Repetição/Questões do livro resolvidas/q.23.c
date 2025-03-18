#include <stdio.h>
#include <stdio.h>

int main()
{
    int i,tipo,cont_c=0;
    float valor_sm,quant_qw,valor_qw,acres,valor_total,faturamento=0,gasto;
    printf("\nValor do salario minino:");
    scanf("%f",&valor_sm);
    for(i=1;quant_qw!=0;i++)
    {
        printf("\nQuantidade de quilowatts:");
        scanf("%f",&quant_qw);
        valor_qw=valor_sm/8;
        printf("\nValor de cada quilowatt: %.2f\n",valor_qw);
        printf("\nTipo do consumidor\n1 - residencial\n2 - comercial\n3 - industrial\n:");
        scanf("%d",&tipo);
        while(tipo!=1 && tipo!=2 && tipo!=3)
        {
            printf("\nDigite OBRIGATORIAMENTE 1,2 ou 3 para receber o tipo:");
            scanf("%d",&tipo);
        }

        switch (tipo)
        {
        case 1:
            acres=valor_qw*0.05;
            break;
        case 2:
            acres=valor_qw*0.10;
            break;
        case 3:
            acres=valor_qw*0.15;
            break;
        default:;
        }
        gasto=quant_qw*valor_qw;
        valor_total=gasto+acres;
        printf("\nValor a ser pago: %.2f\n",valor_total);
        faturamento+=valor_total;
        if (valor_total>=500 && valor_total<=1000)
        {
            cont_c++;
        }
        printf("\nSe deseja encerrar a entrada de dados digite 0\n");
        scanf("%f",&quant_qw);
    }
        printf("\nO faturamento geral da empresa: %.2f",faturamento);
        if (cont_c==0)
        {
            printf("\nNenhum consumidor paga entre 500 e 1000!");
        }
        else
        {
            printf("\nA quantidade de consumidores que pagam entre 500 e 1000: %d",cont_c);
        }
    return 0;
}