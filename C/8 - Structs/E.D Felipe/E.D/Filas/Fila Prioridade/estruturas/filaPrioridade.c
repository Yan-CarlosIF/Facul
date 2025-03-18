#include <stdlib.h>
#include "filaPrioridade.h"

priorityQueue* initQueue() {
    priorityQueue *queue = (priorityQueue*)malloc(sizeof(priorityQueue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    
    return queue;
}

bool isEmpty(priorityQueue *queue) {
    return queue->size == 0;
}

void enqueue(priorityQueue *queue, int value, int priority) {
    Item *newItem = (Item*)malloc(sizeof(Item));

    newItem->value = value;
    newItem->priority = priority;
    newItem->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newItem;
        queue->tail = newItem;
    } else if (newItem->priority > queue->head->priority) {
        // se o novo item tiver prioridade maior que o head adiciona no inicio
        newItem->next = queue->head;
        queue->head = newItem;
    } else {
        Item *current = queue->head;
        
        // loop para encontrar a posicao correta para o novo item
        while (current->next != NULL && current->next->priority >= newItem->priority) 
            current = current->next;
        
        newItem->next = current->next;
        current->next = newItem;

        // se o novo item for o ultimo atualize o tail
        if (newItem->next == NULL) {
            queue->tail = newItem;
        }
    }
    
    queue->size++;
}

int dequeue(priorityQueue *queue) {
    if (isEmpty(queue)) return -1;

    int dequeuedValue = queue->head->value;
    Item *deletedItem = queue->head;

    queue->head = queue->head->next;
    free(deletedItem);
    queue->size--;

    return dequeuedValue;
}

int head(priorityQueue *queue) {
    return queue->head->value;
}

int size(priorityQueue *queue) {
    return queue->size;
}

void displayQueue(priorityQueue *queue) {
    if (!isEmpty(queue)) {
        Item *current = queue->head;

        printf("\nFila: ");
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}