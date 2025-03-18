#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Exercício 5: Reversão de uma String
Escreva um programa que use uma pilha para inverter uma string. A entrada será uma string, e a saída será a string invertida.
*/

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
void reverse(char *str);

int main() {
    char frase[] = "Chama";

    reverse(frase);

    printf("%s", frase);
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

void reverse(char *str) {
    Pilha p;
    inicializarPilha(&p);
    int tam = strlen(str);

    for (int i = 0; i < tam; i++) {
        push(&p, str[i]);
    }

    for (int i = 0; i < tam; i++) {
        str[i] = pop(&p);
    }
    
    str[tam] = '\0';
}