#include <stdio.h>
#include <string.h>

int main()
{
    char nome[4][10];
    float nota[4];
    for (int i=0;i<4;i++)
    {
        printf("Digite o %d nome:",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome),stdin);
        nome[i][strcspn(nome[i],"\n")]='\0';
        printf("Digite a nota de %s:",nome[i]);
        scanf("%f",&nota[i]);
    }
    printf("ALUNO(a)          NOTA\n=========         =====\n");
    for(int i=0;i<4;i++)
    {
        printf("%s           %.1f\n",nome[i]);
    }
    return 0;
}