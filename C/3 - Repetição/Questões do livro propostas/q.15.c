#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexo,res;
    int i,conts=0,contn=0,contfs=0,conth=0,conthn=0;
    for (i = 1; i <=10; i++)
    {   
        do{
        printf("\nDigite o seu sexo:\nM - Masculino\nF - Feminino\n");
        fflush(stdin);
        scanf("%c",&sexo);
        }while((sexo != 'M' && sexo != 'F')&&(sexo != 'm' && sexo != 'f'));
        do
        {
            printf("\nQual foi a sua resposta:\nS - Sim\nN - Nao\n");
            fflush(stdin);
            scanf("%c",&res);
        } while ((res != 'S' && res != 'N')&&(res != 's' && res != 'n'));
        if (res == 'S' || res == 's')
        {
            conts++;
        }
        if (res == 'N' || res == 'n')
        {
            contn++;
        }
        if ((res == 'S' || res == 's')&&(sexo == 'F' || sexo == 'f'))
        {
            contfs++;
        }
        if (sexo == 'M' || sexo == 'm')
        {
            conth++;
            if (res == 'N' || res == 'n')
            {
                conthn++;
            }
        }
    }
    printf("\nO numero de pessoas que responderam sim: %d",conts);
    printf("\nO numero de pessoas que responderam nao: %d",contn);
    printf("\nO numero de mulheres que responderam sim: %d",contfs);
    printf("\nA percentagem de homens que responderam nao, entre todos os homens analisados: %.1f",(conthn/(float)conth)*100);
    return 0;
}