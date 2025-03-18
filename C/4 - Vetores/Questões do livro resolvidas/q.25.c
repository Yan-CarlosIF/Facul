#include <stdio.h>

int main()
{
    int i,j=0,vetor[10],cont_p;
    for (i=100;j<=9;i++)
    {
        cont_p=0;
        for (int k = 1;k<=i;k++)
        {
            if (i%k==0)
            {
                cont_p++;
            }
        }
        if (cont_p==2)
        {
            vetor[j]=i;
            j++;
        }
    }
    printf("Os 10 primeiros primos acima de 100:\n");
    for (i = 0;i<10;i++)
    {
        printf("%d\n",vetor[i]);
    }
    return 0;   
}