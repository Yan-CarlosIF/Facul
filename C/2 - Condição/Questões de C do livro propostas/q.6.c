#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float n1,n2;
    int m;
    printf("Digite um numero:");
    scanf("%f",&n1);
    printf("Digite outro numero:");
    scanf("%f",&n2);
    printf("\nMenu de Operacoes\n1 - para elevar o primeiro numero ao segundo\n2 - para a raiz quadrada de cada um dos numeros\n3 - raiz cubica de cada um dos numeros\n");
    scanf("%d",&m);

    switch (m)
    {
    case 1:
        printf("\nA potencia do primeiro elevado ao segundo:%f",pow(n1,n2));
        break;
    case 2:
        printf("\nRaiz quadrada do primeiro numero:%f\nRaiz quadrada do segundo numero:%f",sqrt(n1),sqrt(n2));
        break;
    case 3:
        printf("\nRaiz cubica do primeiro numero:%f\nRaiz cubica do segundo numero:%f",cbrt(n1),cbrt(n2));
        break;
    default:printf("Numero do menu invalido!");
    }
    return 0;
}