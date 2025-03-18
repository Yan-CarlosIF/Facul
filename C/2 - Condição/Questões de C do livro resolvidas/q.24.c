#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p,va,i,d,pc,np;
    char t,r;
    printf("Digite o preco do produto:");
    scanf("%f",&p);
    printf("\nDigite o tipo\nA - Alimentacao L - Limpeza V - vestuario\n");
    fflush(stdin);
    scanf("%c",&t);
    printf("\nDigite se o produto precisa ou nao de refrigeracao\nS - sim e N - nao\n");
    fflush(stdin);
    scanf("%c",&r);

    switch (r)
    {
    case 'N':
        if (t=='A')
        {
            if (p>=15)
            {
                va=5;
            }
            else
            {
                va=2;
            }
        }
        if (t=='L')
        {
            if (p>=10)
            {
                va=2.5;
            }
            else
            {
                va=1.5;
            }
        }
       
        if (t=='V')
        {
            if (p>=30)
            {
                va=2.5;
            }
            else
            {
                va=3;
            }
        }
        break;
    case 'S':
        if (t=='A')
        {
            va=8;
        }
        else
        {
            va=0;
        }
        break;
    default:printf("Voce digitou uma letra invalida!");
    }
    
    if (p>=25)
    {
        i=p*0.08;
    }
    else
    {
        i=p*0.05;
    }

    pc=p+i;

    if(t=='A' || r=='S')
    {
        d=0;
    }
    else
    {
        d=pc*0.03;
    }

    np=(pc+va)-d;
    
    if (np>=100)
    {
        printf("O novo preco do produto e R$%.2f e esta classificado como Caro",np);
    }
    else if (np>50)
    {
        printf("O novo preco do produto e R$%.2f e esta classificado como Normal",np);
    }
    else
    {
        printf("O novo preco do produto e R$%.2f e esta classificado como Barato",np);
    }
    
    return 0;
}