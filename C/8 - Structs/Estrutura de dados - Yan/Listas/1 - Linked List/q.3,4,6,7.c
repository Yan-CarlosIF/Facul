#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int x;
    struct LinkedList *next;
} LinkedList;

LinkedList *lastElement = NULL;

void insert(LinkedList **list, int element);
void displayList(LinkedList *list);
void removeLast(LinkedList **list);
void freeMemory(LinkedList **list);
LinkedList *searchValue(LinkedList *list, int value);
void reverse(LinkedList **list);
void removeDuplicates(LinkedList **list);

int main()
{
    LinkedList *list = NULL;
    // Insert
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 6);
    displayList(list);

    // removeLast(&list); // removed (Last)

    displayList(list);

    LinkedList *value = searchValue(list, 2);
    if (value != NULL)
    {
        printf("Value %d, was found in the list!\n", value->x);
    }
    else
    {
        printf("Value not found...\n");
    }

    reverse(&list);
    displayList(list);
    removeDuplicates(&list);
    displayList(list);
    return 0;
}

void insert(LinkedList **list, int value)
{
    LinkedList *element = (LinkedList *)malloc(sizeof(LinkedList));
    element->x = value;
    element->next = NULL;

    if (*list == NULL)
    {
        *list = element;
        lastElement = element;
        return;
    }

    lastElement->next = element;
    lastElement = element;
}

void displayList(LinkedList *list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    LinkedList *element = list;

    while (element != NULL)
    {
        printf("%d -> ", element->x);
        element = element->next;
    }
    printf("NULL\n");
}

/* 3. Remover o último elemento da lista
Adicione uma função que remove o último elemento da lista encadeada:

A função deve percorrer a lista e remover o último nó.
Certifique-se de que a memória seja liberada adequadamente. */
void removeLast(LinkedList **list)
{
    if (*list == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if ((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
        return;
    }

    LinkedList *element = *list;

    while (element->next->next != NULL)
        element = element->next;

    free(element->next);
    element->next = NULL;
}

void freeMemory(LinkedList **list)
{
    LinkedList *elements = *list;
    while (elements != NULL)
    {
        LinkedList *aux = elements;
        elements = elements->next;
        free(aux);
    }
    list = NULL;
}

/* 4. Busca por um valor na list encadeada
Implemente uma função que busca por um valor específico dentro da list. A função deve:

Receber um valor como parâmetro e retornar o ponteiro para o nó onde o valor está localizado (ou NULL caso não encontre). */
LinkedList *searchValue(LinkedList *list, int value)
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    LinkedList *elements = list;

    while (elements != NULL)
    {
        if (elements->x == value)
        {
            return elements;
        }
        elements = elements->next;
    }

    return NULL;
}

/* 6. Reverter uma lista encadeada
Implemente uma função para reverter a lista encadeada, ou seja, o primeiro elemento deve se tornar o último e vice-versa:
A função deve percorrer a lista e inverter os ponteiros next de cada nó.*/
void reverse(LinkedList **list)
{
    LinkedList *newList = NULL;
    LinkedList *nextNode = NULL;

    while (*list != NULL)
    {
        nextNode = (*list)->next;
        (*list)->next = newList;
        newList = *list;
        *list = nextNode;
    }

    *list = newList;
}

/* Remover elementos duplicados
Escreva uma função que remove todos os elementos duplicados de uma lista encadeada:

Percorra a lista, comparando cada nó com todos os outros nós subsequentes.
Remova os nós duplicados e libere a memória associada a eles. */
void removeDuplicates(LinkedList **list)
{
    if (*list == NULL) return;  // Se a lista for vazia, não há o que fazer

    LinkedList *atual = *list;

    while (atual != NULL && atual->next != NULL)
    {
        LinkedList *anterior = atual;
        LinkedList *comparador = atual->next;

        // Percorre a lista subsequente ao nó atual, removendo duplicatas
        while (comparador != NULL)
        {
            if (atual->x == comparador->x)
            {
                // Se for duplicado, remove o nó comparador
                anterior->next = comparador->next;
                free(comparador); // Libera a memória do nó duplicado
                comparador = anterior->next; // Atualiza para continuar verificando
            }
            else 
            {
                anterior = comparador;
                comparador = comparador->next;
            }
        }
        atual = atual->next;
    }
}