#include <stdlib.h>
#include "pilha.h"

PilhaInteiros *criarPilhaInteiros() {
    PilhaInteiros *pilha = (PilhaInteiros*)malloc(sizeof(PilhaInteiros));

    pilha->topo = NULL;
    pilha->tamanho = 0;

    return pilha;
}

void empilhar(int valor, PilhaInteiros *pilha) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));

    novoElemento->dado = valor;
    novoElemento->proximo = pilha->topo;
    pilha->topo = novoElemento;

    pilha->tamanho++;
}

int topo(PilhaInteiros *pilha) {
    return pilha->topo->dado;
}

int tirar(PilhaInteiros *pilha) {
    Elemento *itemExcluido = pilha->topo;
    int popedItem = itemExcluido->dado;
    pilha->topo = pilha->topo->proximo;
    
    free(itemExcluido);
    pilha->tamanho--;

    return popedItem;
}

int tamanho(PilhaInteiros *pilha) {
    return pilha->tamanho;
}

bool vazia(PilhaInteiros *pilha) {
    return pilha->tamanho == 0;
}