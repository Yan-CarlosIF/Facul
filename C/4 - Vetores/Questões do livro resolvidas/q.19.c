#include <stdio.h>
#define tam 20

int main()
{
    int i;
    char vetor[tam],vetor2[tam],vetor_aux[tam];
    printf("Digite %d caracteres para o vetor 1:\n",tam);
    for (i = 0; i < tam; i++)
    {
        fflush(stdin);
        scanf("%c",&vetor[i]);
        vetor_aux[i]=vetor[i];
    }
    printf("\nDigite %d caracteres para o vetor 2:\n",tam); 
    for (i = 0; i < tam; i++)
    {
        fflush(stdin);
        scanf("%c",&vetor2[i]);
    }
    printf("\nPrimeiro vetor antes da troca: "); 
    for (i = 0; i < tam;i++)
    {
        printf("%c ",vetor[i]);
    }
    printf("\nSegundo vetor antes da troca: ");
    for (i = 0;i < tam; i++)
    {
        printf("%c ",vetor2[i]);
    }
    int j=tam-1;
    for (i=0;i<tam;i++)
    {
        vetor[i]=vetor2[j];
        j--;
    }
    j=tam-1;
    for (i=0;i<tam;i++)
    {
        vetor2[i]=vetor_aux[j];
        j--;
    }
    printf("\nPrimeiro vetor depois da troca: ");
    for (i=0;i<tam;i++)
    {
        printf("%c ",vetor[i]);
    }
    printf("\nSegundo vetor depois da troca: ");
    for (i=0;i<tam;i++)
    {
        printf("%c ",vetor2[i]);
    }
    return 0;
}