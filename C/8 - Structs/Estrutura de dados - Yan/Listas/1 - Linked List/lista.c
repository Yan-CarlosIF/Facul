#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item *prox;
} Item;

typedef struct {
    Item *head;
    Item *last;
    int tamanho;
} Lista;

Lista* criarLista() {
    Lista *novaLista = (Lista*)malloc(sizeof(Lista));

    novaLista->head = NULL;
    novaLista->last = NULL;
    novaLista->tamanho = 0;
    
    return novaLista;
}

void push(Lista *lista, int valor) {
    Item *novoItem = (Item*)malloc(sizeof(Item));

    novoItem->valor = valor;
    novoItem->prox = NULL;

    if (lista->tamanho == 0) {
        lista->head = novoItem;
        lista->last = novoItem;
    } else {
       lista->last->prox = novoItem;
       lista->last = novoItem;
    }

    lista->tamanho++;
}

int main() {
    Lista *lista = criarLista();

    push(lista, 1);
    push(lista, 2);
    push(lista, 1);

    printf("Tamanho 1: %d\n", lista->tamanho);
    
    return 0;
}
