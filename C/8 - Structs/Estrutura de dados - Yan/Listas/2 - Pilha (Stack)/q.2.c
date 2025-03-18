#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Verificação de Parênteses Balanceados
// Escreva um programa que use uma pilha para verificar se os parênteses em uma expressão estão balanceados. A entrada será uma string que contém parênteses, colchetes e chaves.

// Exemplo de entrada: Ex1: {[()]} ; Ex2: ({[})]

#define MAX 100

typedef struct {
    int topo;
    char string[MAX];
} Pilha;

void inicializarPilha(Pilha *p);
bool estaVazia(Pilha *p);
bool estaCheia(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int peek(Pilha *p);
bool verificaBalanceamento(char str[]);

int main() {
    char expressao[MAX] = "{[()]}", expressao2[MAX] = "({[})]";

    if (verificaBalanceamento(expressao)) {
        printf("esta balanceado\n");
    } else {
        printf("nao esta balanceado\n");
    }

    if (verificaBalanceamento(expressao2)) {
        printf("esta balanceado\n");
    } else {
        printf("nao esta balanceado\n");
    }

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
        p->string[p->topo] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
    }
}

int pop(Pilha *p) {
    if (!estaVazia(p)) {
        int lastEl = p->string[p->topo];
        p->string[p->topo] = 0; 
        p->topo--;
        return lastEl;
    } else {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
}

int peek(Pilha *p) {
    if (!estaVazia(p)) {
        return p->string[p->topo];
    } else {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
}
bool verificaBalanceamento(char str[]) {
    Pilha p;
    inicializarPilha(&p);
    int tam = strlen(str);

    for (int i = 0; i < tam; i++) {
        char atual = str[i];

        if (atual == '(' || atual == '{' || atual == '[') {
            push(&p, atual);
        }

        if (atual == ')' || atual == '}' || atual == ']') {
            if (estaVazia(&p)) {
                return false;
            }

            char topo = pop(&p);
            if ((atual == ')' && topo != '(') ||
                (atual == '{' && topo != '}') ||
                (atual == '[' && topo != ']')) {
                return false;
            }
        }
    }
    return estaVazia(&p);
}