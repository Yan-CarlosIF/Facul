#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade,cont_i=0;
    float m_idade=0;
    do
    {
        printf("\nDigite uma idade:");
        scanf("%d",&idade);
        cont_i++;
        m_idade+=idade;
        printf("\nSe deseja encerrar o programa, digite 0:");
        scanf("%d",&idade);
    }while(idade != 0);
    printf("\nMedia das idades: %.1f",m_idade/(float)cont_i);
    return 0;
}