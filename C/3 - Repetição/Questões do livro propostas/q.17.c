#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,n_canal,p_n4=0,p_n5=0,p_n7=0,p_n12=0;
    do
    {
        printf("\nDigite o canal assistido na sua casa:\nCanais - 4,5,7,12\nSe em sua casa estiver desligada nao digite qualquer outro numero\n:");
        scanf("%d",&n_canal);
        if (n_canal==4)
        {
            p_n4++;
            i++;
        }
        else
        {
            if (n_canal==5)
            {
                p_n5++;
                i++;
            }
            else
            {
                if (n_canal==7)
                {
                    p_n7++;
                    i++;
                }
                else
                {
                    if (n_canal==12)
                    {
                        p_n12++;
                        i++;
                    }
                    else
                    {

                    }
                }
            }
        }
        printf("\nSe deseja terminar a entrada de dados digite 0");
        scanf("%d",&n_canal);
    } while (n_canal!=0);
    printf("\nA porcentagem de audiencia no canal 4: %.1f",(p_n4/(float)i)*100);
    printf("\nA porcentagem de audiencia no canal 5: %.1f",(p_n5/(float)i)*100);
    printf("\nA porcentagem de audiencia no canal 7: %.1f",(p_n7/(float)i)*100);
    printf("\nA porcentagem de audiencia no canal 12: %.1f",(p_n12/(float)i)*100);
    return 0;
}