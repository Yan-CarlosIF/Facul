#include <stdio.h>
#include <stdlib.h>
/*
2. Inserir elemento no início da lista
Altere o exercício anterior para incluir uma função que insere um elemento no início da lista. A função deve:

Receber um valor e inseri-lo como o primeiro nó da lista.
Atualizar o ponteiro da cabeça da lista adequadamente.
*/

typedef struct LinkedList {
    int x;
    struct LinkedList *prox;
} LinkedList;

void insert(LinkedList **lista, int element);
void exibir(LinkedList *lista);
void removeLast(LinkedList **lista);

int main()
{
    LinkedList *lista = NULL;
    // Insert
    insert(&lista, 1); // 1 -> NULL
    insert(&lista, 2); // 2 -> 1 -> NULL
    insert(&lista, 3); // 3 -> 2 -> 1 -> NULL
    removeLast(&lista);

    exibir(lista);

    return 0;
}

void insert(LinkedList **lista, int value)
{
    LinkedList *element = (LinkedList*) malloc(sizeof(LinkedList));
    element->x = value;
    element->prox = *lista;
    *lista = element;
}

void exibir(LinkedList *lista)
{   
    if (lista == NULL) 
    {
        printf("A lista está vazia.\n");
        return;
    }

    LinkedList *element = lista;

    while (element != NULL)
    {
        printf("%d -> ", element->x);
        element = element->prox;
    }
    printf("NULL\n");
}

void removeLast(LinkedList **lista)
{
    if (*lista == NULL)
    {
        printf("Lista ja esta vazia!\n");
    }

    if ((*lista)->prox == NULL)
    {
        free(*lista);
        *lista = NULL;
        return;
    }

    LinkedList *element = *lista;

    while (element->prox->prox != NULL)
    {
        element = element->prox;
    }
    
    free(element->prox);
    element->prox = NULL;
}