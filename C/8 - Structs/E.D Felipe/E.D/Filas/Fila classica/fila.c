#include <stdlib.h>
#include "fila.h"

Queue* initQueue() {
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    
    return queue;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int value) {
    Item *newItem = (Item*)malloc(sizeof(Item));

    newItem->value = value;
    newItem->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newItem;
        queue->tail = newItem;
    } else {
        queue->tail->next = newItem;
        queue->tail = newItem;
    }

    queue->size++;
}

int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        Item *deletedItem = queue->head;
        int dequeuedValue = deletedItem->value;

        queue->head = queue->head->next;
        free(deletedItem);
        
        queue->size--;
        return dequeuedValue;
    }

    return -1;
}

int head(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->head->value;
    }

    return -1;
}

int size(Queue *queue) {
    return queue->size;
}

void displayQueue(Queue *queue) {
    if (!isEmpty(queue)) {
        Item *aux = queue->head;

        printf("\nFila: ");
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
}