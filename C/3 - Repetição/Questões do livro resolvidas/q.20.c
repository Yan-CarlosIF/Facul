#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,cod=1,aulas,v_aulas=30,cont_m=0,cont_f=0;
    float salario_b,salario_l,media_slm=0,media_slf=0;
    char sexo;
    i=1;
    while(cod!=99999)
    {
        printf("\nDigite o codigo do professor(a) %d:",i);
        fflush(stdin);
        scanf("%d",&cod);
        if (cod!=99999)
        {
        printf("\nDigite o Sexo do professor(a)\nM - Masculino\nF - Feminino\n:");
        fflush(stdin);
        scanf("%c",&sexo);
        while (sexo!='M' && sexo!='F')
        {
            printf("\nDigite SOMENTE M ou F para obter o sexo do professor(a)\n:");
            fflush(stdin);
            scanf("%c",&sexo);
        }
        printf("\nDigite o numero de aulas dadas pelo professor(a):");
        scanf("%d",&aulas);
        salario_b=v_aulas*aulas;
        if (sexo=='M')
        {
            salario_l=salario_b-(salario_b*0.10);
            cont_m++;
            media_slm+=salario_l;
        }
        else
        {
            salario_l=salario_b-(salario_b*0.05);
            cont_f++;
            media_slf+=salario_l;
        }
        printf("\n\nListagem do professor(a) %d:\nSeu codigo %d\nSeu salario bruto %.2f\nSeu salario liquido %.2f",i,cod,salario_b,salario_l);
        printf("\n\nSe desejar terminar a entrada de dados, Digite o codigo:99999\n");
        i++;
        }
    }
    if (cont_m==0)
    {
        printf("\nNao teve professores do sexo masculino");
    }
    else
    {
        printf("\nMedia de salario liquidos de professores: %.2f",media_slm/cont_m);
    }
    if (cont_f==0)
    {
        printf("\nNao teve professores do sexo feminino");
    }
    else
    {
        printf("\nMedia de salario liquidos de professoras: %.2f",media_slf/cont_f);
    }
    return 0;
}