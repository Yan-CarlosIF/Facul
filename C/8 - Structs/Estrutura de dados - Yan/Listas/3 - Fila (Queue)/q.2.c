#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 2. Fila Dinâmica:
// Implemente uma fila dinâmica em C utilizando ponteiros e alocação dinâmica de memória. 
// Utilize uma lista encadeada, onde cada nó contém um valor inteiro e um ponteiro para o próximo nó.
// Funções:
// enqueue(int valor): Insere um valor no final da fila.
// dequeue(): Remove e retorna o valor do início da fila.
// isEmpty(): Verifica se a fila está vazia.
// peek(): Retorna o valor do início da fila sem removê-lo.

typedef struct No{
    int x;
    struct No *next;
} No;

typedef struct {
    No *first;
    No *last;
} Fila;

void inicializarFila(Fila *fila);
void enqueue(Fila *fila, int value);
void display(Fila fila);
bool isEmpty(Fila fila);
int dequeue(Fila *fila);
int peek(Fila fila);

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);

    display(fila);

    printf("\nItem excluido = %d\n", dequeue(&fila));
    display(fila);

    printf("\nPrimeiro item da fila = %d\n", peek(fila));

    return 0;
}

void inicializarFila(Fila *fila) {
    fila->first = NULL;
    fila->last = NULL;
}

void enqueue(Fila *fila, int value) {
    
    No *element = (No*)malloc(sizeof(No));
    element->x = value;
    element->next = NULL;

    if (fila->first == NULL) {
        fila->first = element;
        fila->last = element;
    } else {
        fila->last->next = element;
        fila->last = element;
    }

}

void display(Fila fila) {
    if (isEmpty(fila)) {
        printf("Fila esta vazia!\n");
        return;
    }

    No *elements = fila.first;
    printf("\nFila:\n");
    while (elements != NULL) {
        printf("%d -> ", elements->x);
        elements = elements->next;
    }
    printf("NULL");
}

bool isEmpty(Fila fila) {
    return fila.first == NULL;
}

int dequeue(Fila *fila) {
    if (isEmpty(*fila)) {
        printf("Fila esta vazia!\n");
        return -1;
    }

    int popedItem = fila->first->x;
    No *pop = fila->first;
    fila->first = fila->first->next;

    // Se a fila ficar vazia, ajustar o ponteiro `last` também
    if (fila->first == NULL) {
        fila->last = NULL;
    }

    free(pop);
    return popedItem;
}

int peek(Fila fila) {
    if (isEmpty(fila)) {
        printf("Fila esta vazia!\n");
        return -1;
    }
    return fila.first->x;
}