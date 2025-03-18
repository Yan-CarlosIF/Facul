#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int x;
    struct LinkedList *next;
} LinkedList;

void insert(LinkedList **list, int value);
void displayList(LinkedList *list);
void concatList(LinkedList **list1, LinkedList **list2);
int listLen(LinkedList *list);
void splitList(LinkedList *list, LinkedList **firstHalf, LinkedList **secondHalf);
void dividirLista(LinkedList *lista, LinkedList **primeiraMetade, LinkedList **segundaMetade);

int main()
{
    LinkedList *list1 = NULL, *list2 = NULL;
    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);
    insert(&list2, 4);
    insert(&list2, 5);
    insert(&list2, 6);

    printf("\nLista 1:\n");
    displayList(list1);
    printf("\nLista 2:\n");
    displayList(list2);

    printf("\nConcatenacao das listas:\n");
    concatList(&list1, &list2);
    displayList(list1);

    printf("\nTamanho da lista 1: %d\nTamanho da lista 2: %d\n", listLen(list1), listLen(list2));

    LinkedList *firstHalf = NULL, *secondHalf = NULL;
    // splitList(list1, &firstHalf, &secondHalf);
    dividirLista(list1, &firstHalf, &secondHalf);
    printf("\nPrimeira Metade:\n");
    displayList(firstHalf);
    printf("\nSegunda Metade:\n");
    displayList(secondHalf);
    printf("\nLista 1:\n");
    displayList(list1);

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
        return;
    }

    LinkedList *listaAux = *list;
    while (listaAux->next != NULL)
        listaAux = listaAux->next;

    listaAux->next = element;
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

/*
Concatenar duas listas encadeadas
Escreva uma função que concatena duas listas encadeadas:
A função deve unir a segunda lista ao final da primeira.
*/
void concatList(LinkedList **list1, LinkedList **list2)
{
    LinkedList *list1Aux = *list1, *list2Aux = *list2;
    while (list1Aux->next != NULL)
        list1Aux = list1Aux->next;

    list1Aux->next = list2Aux;
}

// Encontrar o tamanho da lista encadeada
// Implemente uma função que calcula e retorna o número de nós em uma lista encadeada:
int listLen(LinkedList *list)
{
    int cont = 0;
    LinkedList *listAux = list;

    while (listAux != NULL)
    {
        cont++;
        listAux = listAux->next;
    }

    return cont;
}

// Dividir uma lista encadeada em duas
// Implemente uma função que divide uma lista encadeada em duas metades. A função deve:
// Dividir a lista original ao meio, considerando a quantidade de elementos.
// Retornar as duas novas listas.
void splitList(LinkedList *list, LinkedList **firstHalf, LinkedList **secondHalf)
{
    if (list == NULL)
    {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    LinkedList *listAux = list;
    int len = listLen(listAux) / 2, cont = 0;

    *firstHalf = listAux;
    LinkedList *first = *firstHalf;

    while (cont < len - 1)
    {
        first = first->next;
        cont++;
    }

    *secondHalf = first->next;
    first->next = NULL;
}

// Dividir a lista sem modificar a lista principal!
void dividirLista(LinkedList *list, LinkedList **firstHalf, LinkedList **secondHalf)
{
    if (list == NULL) {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    int len = listLen(list) / 2, cont = 0;
    LinkedList *listAux = list;

    while (cont < len)
    {
        insert(firstHalf, listAux->x);
        listAux = listAux->next;
        cont++;
    }
    
    while (listAux != NULL)
    {
        insert(secondHalf, listAux->x);
        listAux = listAux->next;
    }
}