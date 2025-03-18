#include <stdio.h>
#include "fila.c"

int main() {
    Queue *queue = initQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    
    printf("Tamanho da fila: %d\n", size(queue));
    printf("Item retirado da fila: %d\n", dequeue(queue));
    printf("Primeiro item da fila: %d\n", head(queue));  
    printf("Tamanho da fila: %d\n", size(queue));

    displayQueue(queue);
    return 0;
}