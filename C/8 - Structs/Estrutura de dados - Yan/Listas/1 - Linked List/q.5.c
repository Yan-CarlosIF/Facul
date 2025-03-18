#include <stdio.h>
#include <stdlib.h>
/*
5. Inserção ordenada em uma lista encadeada
Implemente uma lista encadeada ordenada. A função de inserção deve:

Inserir os elementos na lista de forma que ela se mantenha ordenada em ordem crescente.
Modificar a função de inserção para encontrar o local adequado para o novo nó.
*/
typedef struct LinkedList
{
    int x;
    struct LinkedList *next;
} LinkedList;

void insert(LinkedList **list, int element);
void displayList(LinkedList *list);
void removeLast(LinkedList **list);
void freeMemory(LinkedList **list);
LinkedList *searchValue(LinkedList *list, int value);

int main()
{
    LinkedList *list = NULL;
    // Insert
    insert(&list, 1); 
    insert(&list, 2);
    insert(&list, 3);
    displayList(list);

    removeLast(&list); // removed (Largest)

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

    return 0;
}

void insert(LinkedList **list, int value)
{
    LinkedList *element = (LinkedList *)malloc(sizeof(LinkedList));
    element->x = value;
    element->next = NULL;

    // Caso a lista esteja vazia ou o novo elemento seja menor que o primeiro
    if (*list == NULL || (*list)->x > value)
    {
        // Adiciona o elemento na frente do primeiro
        element->next = *list; // O novo elemento aponta para o antigo primeiro nó
        *list = element;       // O novo elemento se torna o primeiro nó
        return;
    }

    LinkedList *listAux = *list;
    while (listAux->next != NULL && listAux->next->x < value)
        listAux = listAux->next;

    element->next = listAux->next;
    listAux->next = element;
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