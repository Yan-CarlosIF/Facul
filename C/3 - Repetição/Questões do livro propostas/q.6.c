#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i;
    char codigo;
    float valor_tran,valor_av=0,valor_ap=0,valor_c=0,valor_prest;
    for (i = 1; i <=15 ; i++)
    {
        do
        {
            printf("Digite o como deseja pagar a compra %d:\nV - a vista\nP - a prazo\n:",i);
            fflush(stdin);
            scanf("%c",&codigo);

        } while (codigo != 'V' && codigo != 'P');
        printf("\nDigite o preco da compra %d:\n",i);
        scanf("%f",&valor_tran);
        valor_c+=valor_tran;
        if (codigo == 'V')
        {
            valor_av+=valor_tran;
        }
        else
        {
            valor_ap+=valor_tran;
        } 
    }
    valor_prest=valor_ap/3;
    printf("\nValor total das compras a vista: %.2f\n",valor_av);
    printf("Valor total das compras a prazo: %.2f\n",valor_ap);
    printf("Valor da primeira prestacao das compras a prazo: %.2f\n",valor_prest);
    return 0;
}