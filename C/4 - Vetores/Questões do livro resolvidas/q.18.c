#include <stdio.h>

int main()
{
    int i,dado[20],cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0;
    for (i=0;i<20;i++)
    {
        do
        {
        printf("Numero sorteado pelo dado(de 6 lados) na %d jogada:",i+1);
        scanf("%d",&dado[i]);
        } while (dado[i]<1 || dado[i]>6);
        if (dado[i]==1)
        {
            cont1++;
        }
        if (dado[i]==2)
        {
            cont2++;
        }
        if (dado[i]==3)
        {
            cont3++;
        }
        if (dado[i]==4)
        {
            cont4++;
        }
        if (dado[i]==5)
        {
            cont5++;
        }
        if (dado[i]==6)
        {
            cont6++;
        }
    }
    for (i = 0; i < 20; i++)
    {
        printf("jogada numero %d: %d\n",i+1,dado[i]);
    }
    printf("\nO numero 1 foi sorteado %d vez(es)\n",cont1);
    printf("O numero 2 foi sorteado %d vez(es)\n",cont2);
    printf("O numero 3 foi sorteado %d vez(es)\n",cont3);
    printf("O numero 4 foi sorteado %d vez(es)\n",cont4);
    printf("O numero 5 foi sorteado %d vez(es)\n",cont5);
    printf("O numero 6 foi sorteado %d vez(es)\n",cont6);
    return 0;
}