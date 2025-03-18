#ifndef FILA_H
#define FILA_H
#include <stdbool.h>

typedef struct Item {
    int value;
    int priority;
    struct Item *next;
} Item;

typedef struct {
    Item *head;
    Item *tail;
    int size;
} Queue;

Queue* initQueue();
bool isEmpty(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int head(Queue *queue);
int size(Queue *queue);
void displayQueue(Queue *queue);
#endif