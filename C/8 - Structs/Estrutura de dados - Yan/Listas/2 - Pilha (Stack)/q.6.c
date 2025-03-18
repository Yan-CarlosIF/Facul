#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Exercício 6: Implementação de Pilha com Lista Ligada
Implemente a estrutura de uma pilha usando uma lista ligada ao invés de um array. 
Cada nó da lista ligada deverá representar um elemento da pilha.
*/

typedef struct No {
    int data;
    struct No *next;
} No;

typedef struct {
    No *topo;
} Stack;


void inicializarPilha(Stack *p);
void push(Stack *p, int value);
bool estaVazio(Stack *p);
int pop(Stack *p);
int peek(Stack *p);

int main() {
    Stack pilha;
    inicializarPilha(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);

    int popedItem = pop(&pilha);
    printf("Item Popado: %d\n", popedItem);
    printf("Ultimo item: %d\n", peek(&pilha));
    return 0;
}

void inicializarPilha(Stack *p) {
    p->topo = NULL;
}

void push(Stack *p, int value) {
    No *no = (No*)malloc(sizeof(No));

    if (no == NULL) {
        perror("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    no->data = value;
    no->next = p->topo;
    p->topo = no;
}

bool estaVazio(Stack *p) {
    return p->topo == NULL;
}

int pop(Stack *p) {
    No *popedItem = p->topo;
    int lastItem = popedItem->data;
    p->topo = popedItem->next;
    free(popedItem);
    return lastItem;
}

int peek(Stack *p) {
    if (p->topo == NULL) {
        printf("Lista esta vazia!\n");
        return -1;
    }

    return p->topo->data;
}