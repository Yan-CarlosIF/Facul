#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,contb=0,contn=0,contc=0;
    float pu,cs,imp,pf,impt=0,pfm=0,pfme=0,mva=0;
    char r,c;
    for(i=1;i<=12;i++)
    {
        printf("\nDigite o preco unitario do produto %d:",i);
        scanf("%f",&pu);
        printf("\nDigite a refrigeracao do produto\nS - para produtos que precisem\nN - para produtos que nao precisem\n:");
        fflush(stdin);
        scanf("%c",&r);
        while(r != 'S' && r != 'N')
        {
            printf("\nDIGITE S OU N PARA OBTER a refrigeracao do produto\n:");
            fflush(stdin);
            scanf("%c",&r);
        }
        printf("\nDigite a categoria do produto\nA - alimentacao\nL - limpeza\nV - vestuario\n:");
        fflush(stdin);
        scanf("%c",&c);
        while(c != 'A' && c != 'L' && c != 'V')
        {
            printf("\nDIGITE A,L OU V PARA OBTER a categoria do produto\n:");
            fflush(stdin);
            scanf("%c",&c);
        }
        if(pu<=20)
        {
            if(c=='A')
            {
                cs=2;
            }
            else
            {
                if(c=='L')
                {
                    cs=3;
                }
                else
                {
                    cs=4;
                }
            }
        }
        if(pu<=50)
        {
            if(r=='S')
            {
                cs=6;
            }
            else
            {
                cs=0;
            }
        }
        if(pu>50)
        {
            if(r=='S')
            {
                if(c=='A')
                {
                    cs=5;
                }
                else
                {
                    if(c=='L')
                    {
                        cs=2;
                    }
                    else
                    {
                        cs=4;
                    }
                }
            }
            else
            {
                if(c=='A' || c=='V')
                {
                    cs=0;
                }
                else
                {
                    cs=1;
                }
            }
        }
        if(c=='A' || r=='S')
        {
            imp=pu*0.02;
        }
        else
        {
            imp=pu*0.04;
        }
        impt+=imp;
        pf=pu+cs+imp;
        mva+=cs+imp;
        if(pf>pfm)
        {
            pfm=pf;
        }
        else
        {
            pfme=pf;
        }
        if(pf<=20)
        {
            contb++;
        }
        else
        {
            if(pf<=100)
            {
                contn++;
            }
            else
            {
                contc++;
            }
        }
    }
    printf("\nA media dos valores adicionais %.1f",mva/(float)12);
    printf("\nO maior preco final %.2f",pfm);
    printf("\nO menor preco final %.2f",pfme);
    printf("\nO total dos impostos %.2f",impt);
    printf("\nA quantidade de produtos com classificacao barato %d",contb);
    printf("\nA quantidade de produtos com classificacao caro %d",contn);
    printf("\nA quantidade de produtos com classificacao normal %d",contc);
    return 0;
}