#include <stdio.h>

int main()
{
    int i,A[10],cont;
    printf("Digite 10 numeros:\n");
    for (i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }
    for (i=0;i<10;i++)
    {
        int vali = 0;
        cont = 0;
        for (int j=i;j<10;j++)
        {
            if (A[i]==A[j])
            {
                cont++;
            }
        }
        for (int k=0;k<i;k++)
        {
            if (A[i]==A[k])
            {
                vali = 1;
                break;
            }
        }
        if (!vali)
        {
            printf("O numero %d aparece %d vez(es)\n",A[i],cont);
        }
    }
    return 0;
}