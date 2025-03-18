#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,no,npf,tnpf=0,contm=0,contf=0;
    char s;
    float st=0,sm=1000,so,npfh=0,npfm=0,maiorc=0,maiors=0;
    for (i = 1; i <= 15; i++)
    {
        printf("\nQual o numero do %d operario:",i);
        scanf("%d",&no);
        printf("\nQual o numero de pecas fabricadas do %d operario:",i);
        scanf("%d",&npf);
        tnpf+=npf;
        if (npf<=30)
        {
            so=sm;
        }
        else if (npf<=50)
        {
            so=sm+(sm*0.03)*(npf-30);
        }
        else
        {
            so=sm+(sm*0.05)*(npf-30);
        }
        st+=so;
        if(i==1)
        {
            maiors=so;
            maiorc=no;
        }
        if (so>maiors)
        {
            maiors=so;
            maiorc=no;
        }

        printf("\nQual o sexo do %d operario\nM - para masculino\nF - para feminino\n:",i);
        fflush(stdin);
        scanf("%c",&s);

        while (s != 'M' && s != 'F')
        {
            printf("\nSexo do %d operario invalido favor DIGITAR M OU F\n:",i);
            fflush(stdin);
            scanf("%c",&s);
        }
        if (s=='M')
        {
            npfh+=npf;
            contm++;
        }
        else
        {
            npfm+=npf;
            contf++;
        }
        printf("\nO operario de n%d tem o salario de %.2f\n",no,so);
    }
        printf("\nO total da folha de pagamento da fabrica: %.2f",st);
        printf("\nO numero total de pecas fabricadas no mes: %d",tnpf);
        if (contm>0)
        {
            printf("\nA media de pecas fabricadas pelos homens: %.1f",npfh/(float)contm);
        }
        else
        {
            printf("\nNao tem homens na empresa");
        }
        if (contf>0)
        {
            printf("\nA media de pecas fabricadas pelas mulheres: %.1f",npfm/(float)contf);
        }
        else
        {
            printf("\nNao tem mulheres na empresa");
        }
        printf("\nO codigo do operario(a) com maior salario eh %.f",maiorc);
    return 0;
}