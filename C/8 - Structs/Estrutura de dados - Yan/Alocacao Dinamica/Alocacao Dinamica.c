#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que usa malloc para alocar memória para um array de inteiros
void exemploMalloc() {
    int *arr = (int*) malloc(5 * sizeof(int));  // Aloca memória para 5 inteiros

    if (arr == NULL) {  // Verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória com malloc!\n");
        return;
    }

    // Inicializando manualmente o array (malloc não inicializa a memória)
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Exibindo os valores
    printf("Valores alocados com malloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);
}

// Função que usa calloc para alocar e inicializar memória
void exemploCalloc() {
    int *arr = (int*) calloc(5, sizeof(int));  // Aloca e inicializa com 0

    if (arr == NULL) {  // Verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória com calloc!\n");
        return;
    }

    // Exibindo os valores (já inicializados com 0)
    printf("Valores alocados com calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);
}

// Função que usa realloc para redimensionar o array
void exemploRealloc() {
    int *arr = (int*) malloc(5 * sizeof(int));  // Aloca memória para 5 inteiros

    if (arr == NULL) {  // Verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória com malloc!\n");
        return;
    }

    // Inicializando o array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Redimensionando para 10 inteiros
    int *novoArr = (int*) realloc(arr, 10 * sizeof(int));

    if (novoArr == NULL) {  // Verificar se realloc foi bem-sucedido
        printf("Erro ao redimensionar com realloc!\n");
        free(arr);  // Libera a memória original
        return;
    }

    arr = novoArr;

    // Inicializando os novos elementos
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }

    // Exibindo os valores após o realloc
    printf("Valores após realloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);
}

// Função que demonstra o uso correto de free e evitar dangling pointers
void exemploFree() {
    int *arr = (int*) malloc(5 * sizeof(int));  // Aloca memória

    if (arr == NULL) {  // Verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória com malloc!\n");
        return;
    }

    // Inicializando o array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Exibindo os valores
    printf("Valores alocados antes do free:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberando a memória
    free(arr);
    arr = NULL;  // Evita ponteiro pendente

    if (arr == NULL) {
        printf("Memória liberada com sucesso e ponteiro definido para NULL.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu de Exemplos de Alocação Dinâmica:\n");
        printf("1. Exemplo de malloc\n");
        printf("2. Exemplo de calloc\n");
        printf("3. Exemplo de realloc\n");
        printf("4. Exemplo de free\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exemploMalloc();
                break;
            case 2:
                exemploCalloc();
                break;
            case 3:
                exemploRealloc();
                break;
            case 4:
                exemploFree();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}