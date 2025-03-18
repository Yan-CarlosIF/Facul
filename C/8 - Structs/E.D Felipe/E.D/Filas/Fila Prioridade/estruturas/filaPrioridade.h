#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H
#include <stdbool.h>

typedef struct Item {
    int priority;
    int value;
    struct Item *next;
} Item;

typedef struct {
    Item *head;
    Item *tail;
    int size;
} priorityQueue;

priorityQueue* initQueue();
bool isEmpty(priorityQueue *queue);
void enqueue(priorityQueue *queue, int value, int priority);
int dequeue(priorityQueue *queue);
int head(priorityQueue *queue);
int size(priorityQueue *queue);
void displayQueue(priorityQueue *queue);
#endif