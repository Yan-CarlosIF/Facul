#include <stdio.h>
#include <string.h>
#define fun 5

int main()
{
    char nomes[fun][30];
    float salario[fun];
    int i,tempo_ds[fun];
    for (i = 0; i < fun; i++)
    {
        printf("Digite o nome do funcionario %d:",i+1);
        fflush(stdin);
        fgets(nomes[i],sizeof(nomes),stdin);
        nomes[i][strcspn(nomes[i],"\n")]='\0';
        printf("Digite o salario do funcionario %d:",i+1);
        scanf("%f",&salario[i]);
        printf("Digite EM ANOS o tempo de servico do funcionario %d:",i+1);
        scanf("%d",&tempo_ds[i]);
        printf("\n");
    }
    printf("\nRelatorio de funcionarios que não terao aumento:\n");
    for (i = 0; i < fun; i++)
    {
        if (tempo_ds[i]<=5 || salario[i] >=800)
        {
            printf("O funcionario %s recebe %.2f em %d anos de tempo de servico\n",nomes[i],salario[i],tempo_ds[i]);
        }
    }
    printf("\nRelatorio de funcionarios que terao aumento:\n");
    for (i = 0; i < fun; i++)
    {
        if (tempo_ds[i] > 5 && salario[i] < 800)
        {
            salario[i]=salario[i]+(salario[i]*0.35);
            printf("O funcionario %s recebe %.2f em %d anos de tempo de servico\n",nomes[i],salario[i],tempo_ds[i]);
        }
        else if (salario[i] < 800)
        {
            salario[i]=salario[i]+(salario[i]*0.15);
            printf("O funcionario %s recebe %.2f em %d anos de tempo de servico\n",nomes[i],salario[i],tempo_ds[i]);
        }
        else if (tempo_ds[i] > 5)
        {
            salario[i]=salario[i]+(salario[i]/4);
            printf("O funcionario %s recebe %.2f em %d anos de tempo de servico\n",nomes[i],salario[i],tempo_ds[i]);
        }
    }
    return 0;
}