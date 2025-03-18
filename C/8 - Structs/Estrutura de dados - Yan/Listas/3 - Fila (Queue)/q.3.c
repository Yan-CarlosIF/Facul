#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 3. Fila de Prioridade
// Crie uma fila de prioridade em C. Nessa fila, cada elemento tem uma prioridade associada e os elementos são removidos com base na sua prioridade 
//(os de maior prioridade saem primeiro).

// Funções:

// enqueue(int valor, int prioridade): Insere um valor na fila com uma prioridade.
// dequeue(): Remove e retorna o valor de maior prioridade.
// isEmpty(): Verifica se a fila está vazia.
// Dicas:
// Para este exercício, você pode usar uma lista encadeada ou um array para organizar os elementos.

typedef struct No {
    int data;
    int prioridade;
    struct No *prox;
} No;

typedef struct {
    No *fila;
    No *last;
} Fila;

void initQueue(Fila *f);
void enqueue(Fila *f, int valor, int prio);
void display(Fila *f);
bool isEmpty(Fila *f);
int dequeue(Fila *f);

int main() {
    Fila queue;
    initQueue(&queue);
    enqueue(&queue, 1, 2);
    enqueue(&queue, 2, 1);
    enqueue(&queue, 3, 5);

    display(&queue);
    printf("Excluido %d\n", dequeue(&queue));
    display(&queue);

    return 0;
}

void initQueue(Fila *f) {
    f->fila = NULL;
    f->last = NULL;
}

void enqueue(Fila *f, int valor, int prio) {
    No *element = (No*)malloc(sizeof(No));
    element->data = valor;
    element->prioridade = prio;
    element->prox = NULL;

    if (f->fila == NULL) {
        f->fila = element;
        f->last = element;
    } else {
        f->last->prox = element;
        f->last = element;
    }
}

void display(Fila *f) {
    if (isEmpty(f)) {
        printf("Lista Vazia!\n");
        return;
    }
    
    No *temp = f->fila;

    printf("\nFila: ");
    while (temp != NULL) {
        printf("[%d-%d] -> ", temp->data, temp->prioridade);
        temp = temp->prox;
    }
    printf("NULL\n");
}

bool isEmpty(Fila *f) {
    return f->fila == NULL;
}

int dequeue(Fila *f) {
    if (isEmpty(f)) {
        printf("Lista Vazia!\n");
        return -1;
    }

    if (f->fila->prox == NULL) {
        int popedItem = f->fila->data;
        free(f->fila);
        f->fila = NULL;
        return popedItem;
    }

    No *atual = f->fila, *anterior = NULL, *maior = f->fila, *aMaior = NULL;

    while (atual != NULL) {
        if (maior->prioridade < atual->prioridade) {
            maior = atual;
            aMaior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    int popedItem = maior->data;

    if (aMaior == NULL) {
        f->fila = maior->prox;
    } else {
        aMaior->prox = maior->prox;
    }

    if (maior == f->last) {
        f->last = aMaior;
    }

    free(maior);
    return popedItem;
}