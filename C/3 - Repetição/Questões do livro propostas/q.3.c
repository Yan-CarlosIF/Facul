#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
    for (i = 1;i <=8;i++)
    {
        printf("Digite a idade da %d pessoa: ",i);
        scanf("%d",&idade);

        if (idade<=15)
        {
            cont1++;
        }
        else
        {
            if (idade<=30)
            {
                cont2++;
            }
            else
            {
                if (idade<=45)
                {
                    cont3++;
                }
                else
                {
                    if (idade<=60)
                    {
                        cont4++;
                    }
                    else
                    {
                        cont5++;
                    }
                }
                
            }
            
        }
       
    }
    printf("Quantidade de pessoas em cada faixa etaria:\n1 - %d\n2 - %d\n3 - %d\n4 - %d\n5 - %d\n",cont1,cont2,cont3,cont4,cont5);
    printf("Porcentagem de pessoas na 1 faixa etaria: %.1f\n",(cont1/(float)8)*100);
    printf("Porcentagem de pessoas na 5 faixa etaria: %.1f\n",(cont5/(float)8)*100);
    return 0;
}