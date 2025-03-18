#include <stdio.h>

int main()
{
    int i,v[15],p[5],I[5],cont_par=0,cont_imp=0;
    printf("Digite 15 numeros:\n");
    for (i=0;i<15;i++)
    {
        scanf("%d",&v[i]);
    }
    int j=0;
    printf("\nNumeros pares:\n");
     for (i=0;i<15;i++)
    {
        if (v[i]%2==0)
        {
            p[j]=v[i];
            j++;
            cont_par++;
        }
        if (cont_par==5 && i<14)
        {
            for (j=0;j<cont_par;j++)
            {
                printf("%d\n",p[j]);
            }
            cont_par=0;
            j=0;
            printf("Vetor de impares cheio\n");
        }
        if (i==14)
        {
            printf("\nVetor de impares restante\n");
            for (j=0;j<cont_par;j++)
            {
                printf("%d\n",p[j]);
            }
        }        
    }
    j=0;
    printf("\nNumeros impares:\n");
    for (i=0;i<15;i++)
    {
        if (v[i]%2!=0)
        {
            I[j]=v[i];
            j++;
            cont_imp++;
        }
        if (cont_imp==5 && i<14)
        {
            for (j=0;j<cont_imp;j++)
            {
                printf("%d\n",I[j]);
            }
            cont_imp=0;
            j=0;
            printf("Vetor de impares cheio\n");
        }
        if (i==14)
        {
            printf("\nVetor de impares restante\n");
            for (j=0;j<cont_imp;j++)
            {
                printf("%d\n",I[j]);
            }
        }        
    }
    return 0;
}