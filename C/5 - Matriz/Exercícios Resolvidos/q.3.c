#include <stdio.h>
#include <string.h>
#define lojas 8
#define produ 4

int main()
{
    int i,j;
    char nomes_l[lojas][20],nomes_p[lojas][produ][20];
    float precos[lojas][produ];

    for (i=0;i<lojas;i++)
    {
        printf("Digite o nome da %d loja: ",i+1);
        fflush(stdin);
        fgets(nomes_l[i],sizeof(nomes_l),stdin);
        nomes_l[i][strcspn(nomes_l[i],"\n")]='\0';
        printf("\n");
        for (j=0;j<produ;j++)
        {
            printf("Digite o nome do %d produto da loja %s: ",j+1,nomes_l[i]);
            fflush(stdin);
            fgets(nomes_p[i][j],sizeof(nomes_p),stdin);
            nomes_p[i][j][strcspn(nomes_p[i][j],"\n")]='\0';
            printf("\n");
            printf("Digite o preco do produto %s:",nomes_p[i][j]);
            scanf("%f",&precos[i][j]);
            printf("\n");
        }
    }
    for (i=0;i<lojas;i++)
    {
        for (j=0;j<produ;j++)
        {
            if (precos[i][j]<=120)
            {
                printf("%s - %s = %.2f",nomes_l[i],nomes_p[i][j],precos[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}