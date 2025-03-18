#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vsm,ht,vc,i,sb,g,aa,sl;
    char t,c;

    printf("Insira o valor do salario minimo:");
    scanf("%f",&vsm);
    printf("\nInsira o numero de horas trabalhadas:");
    scanf("%f",&ht);
    fflush(stdin);
    printf("\nInsira o turno do trabalho\nM - para Matutino  V - Vespertino  N - Noturno\n:");
    scanf("%c",&t);
    switch (t)
    {
    case 'M':
        vc=vsm*0.10;
        break;
    case 'V':
        vc=vsm*0.15;
        break;
    case 'N':
        vc=vsm*0.12;
        break;
    default:printf("Letra inserida invalida!");
    }

    sb=ht*vc;

    printf("\nInsira a categoria do trabalho\nO - para Operario  G - Gerente\n:");
    fflush(stdin);
    scanf("%c",&c);

    switch (c)
    {
        case 'O':
        if (sb>=300)
        {
            i=sb*0.05;
        }
        else
        {
            i=sb*0.03;
        }
        break;
    case 'G':
        if (sb>=400)
        {
            i=sb*0.06;
        }
        else
        {
            i=sb*0.04;
        }
        break;
    default:printf("letra inserida invalida!");
    }

    if(t=='N' && ht>80)
    {
        g=50;
    }
    else 
    {
        g=30;
    }

    if (c=='O' || vc<=25)
    {
        aa=sb/3;
    }
    else
    {
        aa=sb/2;
    }

    sl=sb-i+g+aa;
    if (sl<350)
    {
        printf("seu salario liquido e de %.2f e voce e mal remunerado!",sl);
    }
    else if (sl<=600)
    {
        printf("seu salario liquido e de %.2f e seu salario e normal",sl);
    }
    else
    {
        printf("seu salario liquido e de %.2f e voce e bem remunerado!",sl);
    }
    return 0;
}