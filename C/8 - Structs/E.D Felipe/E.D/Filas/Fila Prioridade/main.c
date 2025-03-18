#include <stdio.h>
#include "estruturas/filaPrioridade.c"

int main() {
    priorityQueue *queue = initQueue();
    enqueue(queue, 1, 4);
    enqueue(queue, 2, 2);
    enqueue(queue, 3, 2);
    enqueue(queue, 4, 3);
    enqueue(queue, 5, 5);
    enqueue(queue, 6, 1);
    enqueue(queue, 7, 3);
    enqueue(queue, 8, 6);

    printf("Tamanho da fila: %d\n", size(queue));
    printf("Primeiro item da fila: %d\n", head(queue));
    printf("Item retirado da fila: %d\n", dequeue(queue));
    printf("Primeiro item da fila: %d\n", head(queue));
    printf("Tamanho da fila: %d\n", size(queue));

    displayQueue(queue);

    return 0;
}