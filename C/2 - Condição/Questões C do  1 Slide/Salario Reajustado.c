#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[50],funcao[50];
    float salario_a,salario_n,rea;
    printf("Digite seu nome:");
    scanf("%s",&nome);
    printf("\nDigite sua funcao na empresa:");
    fflush(stdin);
    scanf("%s",&funcao);
    printf("\nDigite seu salario atual:");
    scanf("%f",&salario_a);

    if(salario_a>=1000)
    {
        rea=salario_a*0.05;
    }
    else
    {
        if (salario_a>=700)
        {
            rea=salario_a*0.10;
        }
        else
        {
            rea=salario_a*0.15;
        }
    }
    salario_n=salario_a+rea;
    printf("\nNome:%s\nFuncao:%s\nSalario antigo:%.2f\nReajuste:%.2f\nSalario novo:%.2f",nome,funcao,salario_a,rea,salario_n);
    return 0;
}