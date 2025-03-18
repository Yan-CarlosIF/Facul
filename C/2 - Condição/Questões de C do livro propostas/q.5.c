#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2;
    int e;
    printf("Digite o primeiro numero:");
    scanf("%f",&n1);
    printf("Digite o segundo numero:");
    scanf("%f",&n2);
    printf("\nEscolha 1 - para media entre os numeros digitados\nEscolha 2 - para diferenca do maior pelo menor\nEscolha 3 - para produto entre os numeros digitados\nEscolha 4 - para Divisao do primeiro pelo segundo\n");
    scanf("%d",&e);
    
    switch (e)
    {
    case 1:
        printf("a media entre os numeros:%f",(n1+n2)/2);
        break;
    case 2:
        if (n1>n2){
            printf("A diferença do maior para o menor:%f",n1-n2);
        }
        else if(n1<n2){
            printf("A diferença do maior para o menor:%f",n2-n1);
        }
        else{
            printf("Os numeros sao iguais, portando a subtracao resultara em 0");
        }
        break;
    case 3:
        printf("O produto entre os numeros:%f",n1*n2);
        break;
    case 4:
        if (n2==0)
        {
            printf("para a realizacao da divisao e necessario que o segundo numero seja diferente de zero!");
        }
        else
        {
            printf("O resultado da divisao do primeiro pelo segundo:%f",n1/n2);
        }
        break;
    default:printf("escolha invalida!");
    }
    return 0;
}