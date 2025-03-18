#include <stdio.h>
#include <stdlib.h>
// 1. Implementar uma lista encadeada simples
// Crie uma lista encadeada de inteiros e implemente as funções básicas:

// Inserir um novo elemento no final da lista.
// Exibir os elementos da lista.
// Remover o primeiro elemento da lista.
// Liberar toda a memória alocada pela lista.
typedef struct Lista
{
    int x;
    struct Lista *prox;
} Lista;

Lista *lista = NULL;
Lista *ultimoValor = NULL;

void insert(int num);
void exibirLista();
void freeMemory();
void removerPrimeiro();

int main()
{
    insert(1);
    // insert(3);
    // insert(5);

    exibirLista();
    removerPrimeiro();
    exibirLista();
    freeMemory();
    return 0;
}

void insert(int num)
{
    Lista *element = (Lista *)malloc(sizeof(Lista));
    element->x = num;
    element->prox = NULL;

    if (lista == NULL)
    {
        lista = element;
    }
    else
    {
        ultimoValor->prox = element;
    }

    ultimoValor = element;
}

void exibirLista()
{
    Lista *element = lista;
    while (element != NULL)
    {
        printf("%d -> ", element->x);
        element = element->prox;
    }
    printf("NULL\n");
}

void freeMemory()
{
    Lista *element = lista;
    while (element != NULL)
    {
        Lista *temp = element;
        element = element->prox;
        free(temp);
    }
    lista = NULL;
}

void removerPrimeiro()
{
    if (lista == NULL)
    {
        printf("Lista ja esta vazia!\n");
        return;
    }

    Lista *firstElement = lista;
    lista = firstElement->prox;
    free(firstElement);
}