#include <stdio.h>

int main()
{
    int q_vendas[10],i,posicao;
    float valor_u[10],valor_t=0,valor_g=0,comissao=0,valor_maior;

    for (i = 0; i < 10; i++)
    {
        printf("\nDigite o valor unitario do objeto %d:",i+1);
        scanf("%f",&valor_u[i]);
        printf("\nDigite a quantidade vendida do objeto %d:",i+1);
        scanf("%d",&q_vendas[i]);
        if (i==0)
        {
            valor_maior=valor_u[i];
            posicao=i+1;
        }
        if (valor_maior < valor_u[i])
        {
            valor_maior=valor_u[i];
            posicao=i+1;
        }
    }
    for (i = 0; i < 10; i++)
    {
        valor_t=valor_u[i]*q_vendas[i];
        valor_g+=valor_t;
        comissao=valor_g*0.05;
        printf("\nO objeto %d\nSeu Valor unitario %.2f\nQuantidade de vendas %d\nValor total %.2f\n",i+1,valor_u[i],q_vendas[i],valor_u[i]*q_vendas[i]);
    }
    printf("\n\nO valor geral das vendas eh %.2f, e a comissao do vendedor eh %.2f",valor_g,comissao);
    printf("\nO valor do objeto mais vendido eh %.2f e sua posicao no vetor eh %d",valor_maior,posicao);
    return 0;
}