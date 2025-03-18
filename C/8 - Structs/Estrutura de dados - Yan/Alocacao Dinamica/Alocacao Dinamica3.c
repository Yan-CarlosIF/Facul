#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int)); // Aloca memória para 5 inteiros

    if (arr == NULL)
    { // Verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória com malloc!\n");
        return main();
    }

    // Inicializando o array
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    // Redimensionando para 10 inteiros
    int *novoArr = (int *)realloc(arr, 10 * sizeof(int));

    if (novoArr == NULL)
    { // Verificar se realloc foi bem-sucedido
        printf("Erro ao redimensionar com realloc!\n");
        free(arr); // Libera a memória original
        return main();
    }

    arr = novoArr;

    // Inicializando os novos elementos
    for (int i = 5; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    // Exibindo os valores após o realloc
    printf("Valores após realloc:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}