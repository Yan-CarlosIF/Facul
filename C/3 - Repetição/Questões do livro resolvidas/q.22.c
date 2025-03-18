#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade=1,cont_f=0,cont_m=0,cont_f21=0,cont_m45=0,menoridf=0,cont_hexp=0;
    char sexo,exp;
    float idmedia_hexp=0;
    i=1;
    while(idade!=0)
    {
        printf("\nDigite a idade do candidato %d:",i);
        scanf("%d",&idade);
        printf("\nDigite o sexo do candido %d\nM - Masculino\nF - Feminino\n:",i);
        fflush(stdin);
        scanf("%c",&sexo);
        while (sexo!='M' && sexo!='F')
        {
            printf("\nDigite SOMENTE M ou F para obter o sexo do candidato:");
            fflush(stdin);
            scanf("%c",&sexo);
        }
        printf("\nDigite o se o candidato possui ou nao experiencia\nS - para sim\nN - para nao\n:");
        fflush(stdin);
        scanf("%c",&exp);
        while (exp!='S' && exp!='N')
        {
            printf("\nDigite SOMENTE M ou F para obter a experiencia do candidato:");
            fflush(stdin);
            scanf("%c",&exp);
        }
        if(sexo=='M')
        {
            cont_m++;
        }
        if(sexo=='F')
        {
            cont_f++;
        }
        if(sexo=='M' && exp=='S' )
        {
            cont_hexp++;
            idmedia_hexp+=idade;
        }
        if(sexo=='M' && idade>45)
        {
            cont_m45++;
        }
        if(sexo=='F' && exp=='S' && idade<21)
        {
            cont_f21++;
        }
        if(i==1 && sexo=='F')
        {
            menoridf=idade;
        }
        if(menoridf>idade && sexo=='F')
        {
            menoridf=idade;
        }
        printf("\nSe deseja encerrar a entrada de dados digite 0\n");
        scanf("%d",&idade);
        i++;
    }
    printf("\nNumero de candidatas do sexo feminino: %d",cont_f);
    printf("\nNumero de candidatos do sexo Masculino: %d",cont_m);
    printf("\nIdade media dos homens com experiencia: %.1f",idmedia_hexp/(float)cont_hexp);
    printf("\nPorcentagem dos homens com mais de 45 anos: %.1f",(cont_m45/(float)cont_m)*100);
    printf("\nNumero de candidatas do sexo feminino com menos de 21 anos e com experiencia: %d",cont_f21);
    printf("\nMenor idade entre candidatas do sexo feminino que ja tem experiencia: %d",menoridf);
    return 0;
}