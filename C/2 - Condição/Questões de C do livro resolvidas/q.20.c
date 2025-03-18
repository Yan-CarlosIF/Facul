#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cpc,cpo;
    float pk,pg,pt,vi;
    printf("Digite o codigo do pais de origem sendo 1 2 ou 3\n:");
    scanf("%d",&cpo);
    printf("Digite o codigo do produto comprado de 1 a 10\n:");
    scanf("%d",&cpc);
    printf("Digite o peso do produto em KG\n:");
    scanf("%f",&pk);
    pg=((pk*10)*(10))*10;
    
    if (cpc<=4)
    {
        pt=pg*10;
    }
    else if (cpc<=7)
    {
        pt=pg*25;
    }
    else
    {
        pt=pg*35;
    }

    printf("\npreco total:%f",pt);

    switch (cpo)
    {
    case 1:
        vi=pt*0;
        break;
    case 2:
        vi=pt*0.15;
        break;
    case 3:
        vi=pt*0.25;
        break;
    default:printf("Codigo do pais invalido!");
    }

    printf("\nValor Total:%f",pt+vi);
    
    return 0;
}