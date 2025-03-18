#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 12

int main(){
    int i,num_voo[tam],num_lugares[tam],op,consul;
    char origem[tam][50],destino[tam][50];
    for (i=0;i<tam;i++)
    {
        printf("Digite o numero do %d voo:",i+1);
        scanf("%d",&num_voo[i]);
        printf("Digite a origem do %d voo:",i+1);
        fflush(stdin);
        fgets(origem[i],sizeof(origem[i]),stdin);
        origem[i][strcspn(origem[i],"\n")]='\0';
        printf("Digite o destino do %d voo:",i+1);
        fflush(stdin);
        fgets(destino[i],sizeof(destino[i]),stdin);
        destino[i][strcspn(destino[i],"\n")]='\0';
        printf("Digite o numero de lugares do %d voo:",i+1);
        scanf("%d",&num_lugares[i]);
        printf("\n");
    }
    do
    {
    printf("Se deseja Consultar digite: 1\nSe deseja efetuar reserva digite: 2\nSe deseja sair digite: 3\n:");
    scanf("%d",&op);
    if (op == 1)
    {
        printf("\n");
        do
        {
            printf("Digite:\n1 - para consultar pelo numero do voo\n2 - para consultar por origem\n3 - para consultar por destino\n:");
            scanf("%d",&consul);
        } while(consul != 1 && consul != 2 && consul != 3);
        if (consul == 1)
        {
            int vali = 1;
            int voo;
            printf("\nDigite o numero do voo que deseja consultar:");
            scanf("%d",&voo);
            for (i=0;i<tam;i++)
            {
                if (voo==num_voo[i])
                {
                    printf("\nO numero do voo %d\n",num_voo[i]);
                    printf("Com origem de %s e destino a %s\n\n",origem[i],destino[i]);
                    vali = 0;
                }
                else
                {
                    vali++;
                }
            }
            if (vali==tam+1)
            {
                printf("Numero do voo inexistente!\n\n");
            }
        }
        else if(consul == 2)
        {
            int vali = 1;
            char ori[50];
            printf("\nDigite a origem do voo que deseja consultar:");
            fflush(stdin);
            fgets(ori,sizeof(ori),stdin);
            ori[strcspn(ori,"\n")]='\0';
            for (i=0;i<tam;i++)
            {
                if (strcmpi(ori,origem[i])==0)
                {
                    printf("\nO numero do voo %d\n",num_voo[i]);
                    printf("Com origem de %s e destino a %s\n\n",origem[i],destino[i]);
                }
                else
                {
                    vali++;
                }
            }
            if (vali==tam+1)
            {
                printf("Origem do voo inexistente!\n\n");
            }
        }
        else if (consul == 3)
        {
            int vali = 1;
            char des[50];
            printf("\nDigite o destino do voo que deseja consultar:");
            fflush(stdin);
            fgets(des,sizeof(des),stdin);
            des[strcspn(des,"\n")]='\0';
            for (i=0;i<tam;i++)
            {
                if(strcmpi(des,destino[i])==0)
                {
                    printf("\nO numero do voo %d\n",num_voo[i]);
                    printf("Com origem de %s e destino a %s\n\n",origem[i],destino[i]);
                }
                else
                {
                    vali++;
                }
            }
            if (vali==tam+1)
            {
                printf("Destino do voo inexistente!\n\n");
            }
        }
    }
    else if(op == 2)
    {
        int vali = 1;
        int voo;
        printf("\nDigite o numero do voo que deseja viajar:");
        scanf("%d",&voo);
        for (i=0;i<tam;i++){
            if (voo==num_voo[i])
            {
                if (num_lugares[i]>0)
                {
                    printf("\nReserva confirmada!\n\n");
                    num_lugares[i]--;
                }
                else
                {
                    printf("\nVoo lotado!\n\n");
                }
            }
            else
            {
                vali++;
            }
        }
        if (vali==tam+1)
        {
            printf("Voo inexistente!\n\n");
        }
    }
    } while (op != 3);
    system("\nPAUSE");
    return 0;
}