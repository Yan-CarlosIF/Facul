#include <stdio.h>
#include <stdlib.h>
#include "../../E.D/Filas/Fila Prioridade/estruturas/filaPrioridade.c"

void enqueue2(priorityQueue *queue, int value, int priority) {
    Item *newItem = (Item*)malloc(sizeof(Item));

    newItem->value = value;
    newItem->priority = priority;
    newItem->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newItem;
        queue->tail = newItem;
    } else if (newItem->priority > queue->head->priority) {
        newItem->next = queue->head;
        queue->head = newItem;
    } else {
        Item *aux = queue->head;

        while (aux->next != NULL && aux->next->priority >= newItem->priority) 
            aux = aux->next;

        newItem->next = aux->next;
        aux->next = newItem;

        if (newItem->next == NULL) {
            queue->tail = newItem;
        }
    }

    queue->size++;
}

int main() {
    priorityQueue *queue = initQueue();

    enqueue2(queue, 1, 4);
    enqueue2(queue, 2, 2);
    enqueue2(queue, 3, 2);
    enqueue2(queue, 4, 3);
    enqueue2(queue, 5, 5);
    enqueue2(queue, 6, 1);
    enqueue2(queue, 7, 3);
    enqueue2(queue, 8, 6);

    printf("Tamanho da fila: %d\n", size(queue));
    printf("Primeiro item da fila: %d\n", head(queue));
    printf("Item retirado da fila: %d\n", dequeue(queue));
    printf("Primeiro item da fila: %d\n", head(queue));
    printf("Tamanho da fila: %d\n", size(queue));

    displayQueue(queue);
}