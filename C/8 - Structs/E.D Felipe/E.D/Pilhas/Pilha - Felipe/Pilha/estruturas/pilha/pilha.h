#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilhaInteiros {
    Elemento *topo;
    int tamanho;
} PilhaInteiros;

PilhaInteiros *criarPilhaInteiros();
void empilhar(int valor, PilhaInteiros *pilha);
int topo(PilhaInteiros *pilha);
int tirar(PilhaInteiros *pilha);
int tamanho(PilhaInteiros *pilha);
bool vazia(PilhaInteiros *pilha);
#endif