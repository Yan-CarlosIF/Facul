#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,c;
    float nht,vht,sm=450;
    char tu,ca;
    for (i = 1; i <=10; i++)
    {
        printf("\nDigite o codigo do funcionario:");
        scanf("%d",&c);
        printf("\nDigite o numero de horas trabalhadas do funcionario:");
        scanf("%f",&nht);
        printf("\nDigite o Turno do trabalho\nM - matutino\nV - vespertino\nN - noturno\n");
        fflush(stdin);
        scanf("%c",&tu);
        while(tu !='V' && tu  != 'N' && tu  != 'M')
        {
            printf("\nDigite o Turno do trabalho\nM - matutino\nV - vespertino\nN - noturno\n");
            fflush(stdin);
            scanf("%c",&tu);
        }
        printf("\nDigite o categoria funcionario\nO - operario ou G - gerente\n");
        fflush(stdin);
        scanf("%c",&ca);
        while(ca !='O' && ca  != 'G')
        {
            printf("\nDigite o categoria funcionario\nO - operario ou G - gerente\n");
            fflush(stdin);
            scanf("%c",&ca);
        }
        switch (ca)
        {
        case 'G':
            if (tu=='N')
            {
                vht=sm*0.18;
            }
            else
            {
                vht=sm*0.15;
            }
            break;
        case 'O':
            if (tu=='N')
            {
                vht=sm*0.13;
            }
            else
            {
                vht=sm*0.10;
            }
            break;
            default:printf("YAN PIKUDO");
        }
        float si,sf,aux;
        si=vht*nht;
        if (si<=300)
        {
            aux=si*0.20;
        }
        else if (si<=600)
        {
            aux=si*0.15;
        }
        else
        {
            aux=si*0.05;
        }
        sf=si+aux;
        printf("\nO funcionario de codigo %d\nTrabalhou %.2f horas\nValor de sua hora trabalhada foi %.2f\nSeu salario inicial foi %.2f\nAuxilio alimentacao de %.2f\nE salario final de %.2f\n",c,nht,vht,si,aux,sf);
    }
    return 0;
}