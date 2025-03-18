#include <stdio.h>
#define conta 10
int main()
{
    int i,cod[conta],vali,cond,codi;
    float saldo[conta],valor,soma;
    for (i=0;i<conta;i++)
    {
        do 
        {
        vali = 0;
        printf("Insira o codigo da %d conta:",i+1);
        scanf("%d",&cod[i]);
        for (int j=0;j<i;j++)
        {
            if (cod[i]==cod[j])
            {
                vali = 1;
                break;
            }
        }
        if (vali)
        {
            printf("\nCodigo inserido ja existente!\n");
        }
        } while (vali);
        printf("Insira o saldo da conta %d:",cod[i]);
        scanf("%f",&saldo[i]);
    }
    do
    {
        printf("Digite:\n1 - Efetuar deposito\n2 - Efetuar saque\n3 - Consultar o ativo bancario\n4 - Finalizar o programa\n:");
        scanf("%d",&cond);
        switch (cond)
        {
            case 1:
                vali = 0;
                printf("\nVoce escolheu efetuar deposito\n");
                do{
                    printf("\nInsira o codigo da conta que deseja depositar:");
                    scanf("%d",&codi);
                    for (i=0;i<conta;i++)
                    {
                        if (codi==cod[i])
                        {
                            vali = 1;
                            printf("\nInsira o valor do deposito:");
                            scanf("%f",&valor);
                            saldo[i]+=valor;
                            printf("\nO saldo apos o deposito: %.2f\n\n",saldo[i]);
                            break;
                        }
                    }
                    if(!vali)
                    {
                        printf("\nConta nao encontrada!\n");  
                    }
                } while (!vali);
                break;
            case 2:
                vali = 0;
                printf("\nVoce escolheu efetuar saque\n");
                do
                {
                    printf("\nInsira o codigo da conta que deseja sacar:");
                    scanf("%d",&codi);
                    for (i=0;i<conta;i++)
                    {
                        if (codi==cod[i])
                        {
                            vali = 1;
                            printf("\nInsira o valor que deseja sacar:");
                            scanf("%f",&valor);
                            if (saldo[i]>=valor)
                            {
                                saldo[i]-=valor;
                                printf("\nO saldo apos o saque: %.2f\n\n",saldo[i]);
                            }
                            else
                            {
                                printf("\nSaldo insuficiente!\n\n");
                            }
                            break;
                        }
                    }
                    if (!vali)
                    {
                        printf("\nConta nao encontrada!\n");   
                    }
                } while (!vali);
                break;
            case 3:
                vali = 0;
                soma = 0;
                printf("\nVoce escolheu consultar o ativo bancario\n");
                for (i=0;i<conta;i++)
                {
                    soma += saldo[i];
                }
                printf("\nO valor do ativo bancario: %.2f\n\n",soma);
                break;
            default:;
        }
    } while (cond != 4);
    
    return 0;
}