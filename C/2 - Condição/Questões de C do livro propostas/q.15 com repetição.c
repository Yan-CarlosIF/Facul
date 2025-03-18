#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,m;
    float vi;
    printf("Digite o valor do investimento:");
    scanf("%f",&vi);
    printf("\nDigite o tipo do investimento\n1 - Poupanca 2 - Fundos de renda fixa\n");
    scanf("%d",&t);
    printf("\nDigite a quantidade de meses que deseja investir:");
    scanf("%d",&m);


    switch (t)
    {
    case 1:
        for (i = 1; i <= m; i++)
        {
            printf("valor apos %d meses eh %.2f\n",i,vi+=(vi*0.03));
        }
        break;
    case 2:
        for (i = 1; i <= m; i++)
        {
            printf("valor apos %d meses eh %.2f\n",i,vi+=(vi*0.04));
        }
        break;
    default:printf("Tipo de investimento invalido!");
    }
    system("PAUSE");
    return 0;
}