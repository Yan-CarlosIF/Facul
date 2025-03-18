#include "pilha.h"
#include <stdbool.h>
#include <stdlib.h>

Pilha* inicializarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));

    p->topo = NULL;
    p->tamanho = 0;
    
    return p;
}

bool isEmpty(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));

    novoElemento->valor = valor;
    novoElemento->prox = p->topo;
    p->topo = novoElemento;

    p->tamanho++;
}

int pop(Pilha *p) {
    Elemento *ElementoExcluido = p->topo;
    int valor = ElementoExcluido->valor;

    p->topo = ElementoExcluido->prox;
    free(ElementoExcluido);

    p->tamanho--;
    return valor;
}

int peek(Pilha *p) {
    return p->topo->valor;
}

int size(Pilha *p) {
    return p->tamanho;
}