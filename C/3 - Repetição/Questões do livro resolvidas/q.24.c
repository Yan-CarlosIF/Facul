#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op=0;
    float salario,imp;
    while (op!=4)
    {
        printf("\nMenu:\n1 - Imposto\n2 - Novo salario\n3 - Classificacao\n4 - Finalizar o Programa\n:");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\nDigite o salario:");
            scanf("%f",&salario);
            if (salario<500)
            {
                imp=salario*0.05;
                printf("\nO valor do imposto eh %.2f",imp);
            }
            else if (salario<=850)
            {
                imp=salario*0.10;
                printf("\nO valor do imposto eh %.2f",imp);
            }
            else
            {
                imp=salario*0.15;
                printf("\nO valor do imposto eh %.2f",imp);
            }
            break;
        case 2:
            printf("\nDigite o salario:");
            scanf("%f",&salario);
            if (salario>1500)
            {
                printf("\nNovo salario eh %.2f",salario+25);
            }
            else if (salario>=750)
            {
                printf("\nNovo salario eh %.2f",salario+50);
            }
            else if (salario>=450)
            {
                printf("\nNovo salario eh %.2f",salario+75);
            }
            else
            {
                printf("\nNovo salario eh %.2f",salario+100);
            }
            break;
        case 3:
            printf("\nDigite o salario:");
            scanf("%f",&salario);
            if (salario<=700)
            {
                printf("\nSeu salario eh %.2f, e voce eh liso!",salario);
            }
            else
            {
                printf("\nSeu salario eh %.2f, e voce eh bem remunerado!",salario);
            }
            break;
        default:;
        }
    }
    return 0;
}