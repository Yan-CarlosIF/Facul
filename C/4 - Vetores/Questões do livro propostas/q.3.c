#include <stdio.h>

int main(){
    int i,cod[10],estoque[10],codc,codp,quant,vali,posi;

    for(i = 0; i < 10; i++)
    {
        printf("Digite o codigo do produto %d:\n",i+1);
        scanf("%d", &cod[i]);
    }
    
    for(i = 0; i < 10 ; i++)
    {
        printf("Digite o total do estoque do produto %d:\n",i+1);
        scanf("%d", &estoque[i]);
    }
    
    do
    {
    	vali = 0;
        printf("\nDigite o codigo do cliente:");
        scanf("%d",&codc);
        printf("\nDigite o codigo do produto que deseja comprar:");
        scanf("%d",&codp);
        for (i = 0; i < 10; i++)
        {
            if (codp == cod[i])
            {
                printf("codigo valido");
                vali = 1;
                posi = i;
            }
        }
        if (vali == 0)
        {
            printf("Codigo inexistente");
        }
        else
        {
            printf("\nDigite a quantidade que deseja adquirir desse produto:");
            scanf("%d", &quant);
            if (quant <= estoque[posi])
            {
                printf("\nPedido atendido. Obrigado e volte sempre");
                estoque[posi] -= quant;
            }
            else
            {
                printf("\nNao temos estoque o suficiente dessa mercadoria");
            }
        }
        printf("\nCaso deseje encerrar as compras digite 0\n");
        scanf("%d",&codc);
    } while(codc != 0);

    printf("\nCompra Finalizada!\n");

    for (i = 0; i < 10; i++)
    {
        printf("Codigo %d - seu estoque: %d\n",cod[i],estoque[i]);
    }
    return 0;
}