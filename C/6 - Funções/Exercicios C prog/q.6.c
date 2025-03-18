#include <stdio.h>

int maiorr(int vet[3],int m)
{
    m=0;
    for (int i=0;i<3;i++)
    {
        if (vet[i] > m)
        {
            m = vet[i];
        }
    }
    return m;
}

int main()
{
    int num[3];
    printf("Digite 3 numeros:");
    for (int i=0;i<3;i++)
    {
        scanf("%d",&num[i]);
    }

    int maior_num = maiorr(num,0);
    
    printf("\nO maior: %d",maior_num);
    return 0;
}