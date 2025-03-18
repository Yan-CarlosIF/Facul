#include <stdio.h>

int main()
{
    int t;
    float vi;
    printf("Digite o valor do investimento:");
    scanf("%f",&vi);
    printf("\nDigite o tipo do investimento\n1 - Poupanca 2 - Fundos de renda fixa\n");
    scanf("%d",&t);

    switch (t)
    {
    case 1:
        printf("valor apos um mes %.2f",vi+(vi*0.03));
        break;
    case 2:
        printf("valor apos um mes %.2f",vi+(vi*0.04));
        break;
    default:printf("Tipo de investimento invalido!");
    }
    
    return 0;
}