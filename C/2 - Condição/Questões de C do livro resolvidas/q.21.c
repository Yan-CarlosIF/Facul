#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cde,cdg;
    float pct,pck,prg,vi;
    printf("Digite o codigo do estado de origem\nnumero de 1 a 5:\n");
    scanf("%d",&cde);
    printf("Digite o peso em toneladas do caminhao:\n");
    scanf("%f",&pct);
    printf("Digite o codigo da carga\nnumero de 10 a 40:\n");
    scanf("%d",&cdg);
    pck=pct*1000;
    
    if (cdg<=20)
    {
        prg=pck*100;
    }
    else if (cdg<=30)
    {
        prg=pck*250;
    }
    else
    {
        prg=pck*340;
    }

    switch (cde)
    {
    case 1:
        vi=prg*0.35;
        break;
    case 2:
        vi=prg*0.25;
        break;
    case 3:
        vi=prg*0.15;
        break;
    case 4:
        vi=prg*0.05;
        break;
    case 5:
        vi=prg*0;
        break;
    default:printf("Codigo do estado invalido!");
    }

    printf("\nValor total:%f",prg+vi);
    return 0;
}