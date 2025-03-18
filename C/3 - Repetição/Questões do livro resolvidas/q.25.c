#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pais_o;
    float preco_u,t_valor,imposto,v_seguro,preco_f,totalimp=0;
    char meio_t,carga_p;
    while(preco_u>0)
    {
        printf("\nDigite o preco unitario do produto:");
        scanf("%f",&preco_u);
        printf("\nDigite o codigo do pais de origem:\n1 - EUA\n2 - MEX\n3 - Outro\n:");
        scanf("%d",&pais_o);
        while (pais_o != 1 && pais_o != 2 && pais_o	!= 3)
        {
            printf("\nDigite OBRIGATORIAMENTE 1,2 OU 3 para obter codigo do pais de origem:");
            scanf("%d",&pais_o);
        }
        printf("\nDigite o meio de transporte do produto:\nT - terrestre\nF - fluvial\nA - aereo\n:");
        fflush(stdin);
        scanf("%c",&meio_t);
        while (meio_t != 'T' && meio_t != 'A' && meio_t != 'F')
        {
            printf("\nDigite OBRIGATORIAMENTE T,F OU A para obter o meio de transporte:");
            fflush(stdin);
            scanf("%c",&meio_t);
        }
        printf("\nO produto eh uma cara perigosa?:\nS - para sim\nN - para nao\n:");
        fflush(stdin);
        scanf("%c",&carga_p);
        while (carga_p != 'S' && carga_p != 'N')
        {
            printf("\nDigite OBRIGATORIAMENTE S OU N para saber se produto eh uma cara perigosa:");
            fflush(stdin);
            scanf("%c",&carga_p);
        }
        if (preco_u <= 100)
        {
            imposto=preco_u*0.05;
            printf("\nO preco do imposto: %.2f",imposto);
        }
        else
        {
            imposto=preco_u*0.10;
            printf("\nO preco do imposto: %.2f",imposto);
        }
        if (carga_p == 'S')
        {
            if (pais_o == 1)
            {
                t_valor=50;
                printf("\nO valor do transporte: %.2f",t_valor);
            }
            else if (pais_o == 2)
            {
                t_valor=21;
                printf("\nO valor do transporte: %.2f",t_valor);
            }
            else
            {
                t_valor=24;
                printf("\nO valor do transporte: %.2f",t_valor);
            }  
        }
        else
        {
            if (pais_o == 1)
            {
                t_valor=12;
                printf("\nO valor do transporte: %.2f",t_valor);
            }
            else if (pais_o == 2)
            {
                t_valor=21;
                printf("\nO valor do transporte: %.2f",t_valor);
            }
            else
            {
                t_valor=60;
                printf("\nO valor do transporte: %.2f",t_valor);
            }
        }
        if (pais_o == 2 || meio_t == 'A')
        {
            v_seguro=preco_u/2;
            printf("\nO valor do seguro: %.2f",v_seguro);
        }
        else
        {
            v_seguro=0;
            printf("\nO produto nao possui valor do seguro!");
        }
        preco_f=preco_u+imposto+t_valor+v_seguro;
        printf("\nPreco final: %.2f",preco_f);
        totalimp+=imposto;
        printf("\nSe desejas finalizar a entrada de dados digite 0 ou um numero negativo:\n");
        scanf("%f",&preco_u);
    }
        printf("\nO total dos impostos de todos os produtos recebidos: %.2f",totalimp);
    return 0;
}