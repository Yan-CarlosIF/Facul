#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. Implementação de uma Fila Simples (FIFO)
// Crie um programa em C que implemente uma fila simples de inteiros utilizando arrays. A fila deve suportar as seguintes operações:

// enqueue(int valor): Insere um valor no final da fila.
// dequeue(): Remove e retorna o valor do início da fila.
// isEmpty(): Verifica se a fila está vazia.
// isFull(): Verifica se a fila está cheia.
// peek(): Retorna o valor do início da fila sem removê-lo.
// Desafio:
// Tente implementar a fila usando um array circular para otimizar o uso de espaço

#define TAM 5
typedef struct Queue {
    int array[TAM];
    int frente;
    int fim;
} Queue;

void initQueue(Queue *fila);
bool isFull(Queue fila);
bool isEmpty(Queue fila);
void enqueue(Queue *fila, int valor);
int dequeue(Queue *fila);
void display(Queue *fila);
int peek(Queue fila);

int main() {
    Queue fila;
    initQueue(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    enqueue(&fila, 4);
    enqueue(&fila, 5);

    display(&fila);

    printf("\nItem retirado da fila: %d\n", dequeue(&fila));

    printf("\nPrimeiro item da fila: %d\n", peek(fila));

    display(&fila);
    return 0;
}

void initQueue(Queue *fila) {
    fila->frente = -1;
    fila->fim = -1;
}

bool isFull(Queue fila) {
    if ((fila.frente == 0 && fila.fim == TAM - 1) || (fila.frente == fila.fim + 1)) {
        return true;
    }
    return false;
}

bool isEmpty(Queue fila) {
    return fila.frente == -1;
}

void enqueue(Queue *fila, int valor) {
    if (isFull(*fila)) {
        printf("Fila cheia!\n");
        return;
    }

    if (isEmpty(*fila)) {
        fila->frente = 0;
    }

    fila->fim = (fila->fim + 1) % TAM;
    fila->array[fila->fim] = valor;
}

int dequeue(Queue *fila) {
    int elemento;
    if (isEmpty(*fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    elemento = fila->array[fila->frente];

    if (fila->fim == fila->frente) {
        fila->fim = -1;
        fila->frente = -1;
    } else {
        fila->frente = (fila->frente + 1) % TAM;
    }

    return elemento;
}

void display(Queue *fila) {
    if (isEmpty(*fila)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila:\n");
    for (int i = fila->frente; i <= fila->fim; i++) {
        printf("%d ", fila->array[i]);
    }
}

int peek(Queue fila) {
    if (isEmpty(fila)) {
        printf("Lista vazia!\n");
        return -1;
    }

    return fila.array[fila.fim];
}