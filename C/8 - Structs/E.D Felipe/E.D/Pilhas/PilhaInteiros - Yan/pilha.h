#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct Elemento {
    int valor;
    struct Elemento *prox;
} Elemento;

typedef struct {
    Elemento *topo;
    int tamanho;
} Pilha;

Pilha* inicializarPilha();
bool isEmpty(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int peek(Pilha *p);
int size(Pilha *p);
#endif