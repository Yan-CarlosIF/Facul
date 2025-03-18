#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Exercício 1: Implementação Básica de Pilha
Implemente uma pilha usando um array. A pilha deve suportar as operações básicas:

push (inserir um elemento no topo),
pop (remover o elemento do topo),
peek (observar o elemento do topo sem removê-lo),
verificar se a pilha está cheia ou vazia.
*/

#define MAX 50

typedef struct {
    int topo;
    int elementos[MAX];
} Pilha;

void inicializarPilha(Pilha *p);
bool estaVazia(Pilha *p);
bool estaCheia(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int peek(Pilha *p);

int main() {
    Pilha stack = {0};
    inicializarPilha(&stack);

    for (int i = 0; i < MAX; i++) {
        push(&stack, i + 1);
    }

    if (estaCheia(&stack)) {
        printf("Pilha esta cheia");
    }

    printf("\nPop = %d\n", pop(&stack));
    printf("Peek = %d\n", peek(&stack));
    return 0;
}

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

bool estaCheia(Pilha *p) {
    return p->topo >= MAX - 1;
}

void push(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->topo++;
        p->elementos[p->topo] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
    }
}

int pop(Pilha *p) {
    if (!estaVazia(p)) {
        int lastEl = p->elementos[p->topo];
        p->elementos[p->topo] = 0; 
        p->topo--;
        return lastEl;
    } else {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
}

int peek(Pilha *p) {
    if (!estaVazia(p)) {
        return p->elementos[p->topo];
    } else {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
}