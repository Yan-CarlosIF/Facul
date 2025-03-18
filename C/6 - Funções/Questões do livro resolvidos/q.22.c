#include <stdio.h>

int preencheArrImpar(int *arrOrigem, int *arrDestino, int tam);
int preencheArrPar(int *arrOrigem, int *arrDestino, int tam);
void preencheArr(int *arr, int tam);

int main()
{
    int vetor[8], vetPar[8], vetImp[8];

    preencheArr(vetor, 8);
    int tamPar = preencheArrPar(vetor, vetPar, 8);
    int tamImpar = preencheArrImpar(vetor, vetImp, 8);

    printf("\nVetor Original:\n");
    exibeVet(vetor, 8);
    printf("\nVetor Par:\n");
    exibeVet(vetPar, tamPar);
    printf("\nVetor Impar:\n");
    exibeVet(vetImp, tamImpar);

    return 0;
}

void preencheArr(int *arr, int tam)
{
    printf("Preencha o array com %d numeros:", tam);
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int preencheArrPar(int *arrOrigem, int *arrDestino, int tam)
{
    int contP = 0;
    for (int i = 0; i < tam; i++)
    {
        if (arrOrigem[i] > 0)
        {
            arrDestino[contP++] = arrOrigem[i];
        }
    }

    if (!contP)
    {
        printf("\nNenhum numero positivo foi passado!");
        return contP;
    }
    else
    {
        return contP;
    }
}

int preencheArrImpar(int *arrOrigem, int *arrDestino, int tam)
{
    int contImp = 0;
    for (int i = 0; i < tam; i++)
    {
        if (arrOrigem[i] < 0)
        {
            arrDestino[contImp++] = arrOrigem[i];
        }
    }

    if (!contImp)
    {
        printf("\nNenhum numero negativo foi passado!");
        return contImp;
    }
    else
    {
        return contImp;
    }
}

void exibeVet(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
}
