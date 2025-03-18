#include <stdio.h>

void ordenaCrescente(float *arr, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i; j < tam; j++)
        {
            if (arr[i] > arr[j])
            {
                float aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
        printf("%.1f ", arr[i]);
    }
}

int main()
{
    float arr[5];

    printf("Digite 5 numeros:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &arr[i]);
    }

    printf("\nArray ordem crescente:\n");
    ordenaCrescente(arr, 5);
    return 0;
}