#include <stdio.h>

void MaiorMenor(int *arr, int tam)
{
    int maior = arr[0], menor = arr[0];
    for (int i = 0; i < tam; i++)
    {
        if (maior < arr[i])
        {
            maior = arr[i];
        }
        if (menor > arr[i])
        {
            menor = arr[i];
        }
    }

    printf("\nMaior = %d\nMenor = %d\n", maior, menor);
}

int main()
{   
    const int tam = 5;
    int nums[tam];

    printf("Digite %d numeros:", tam);
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &nums[i]);
    }

    MaiorMenor(nums, tam);

    return 0;
}

