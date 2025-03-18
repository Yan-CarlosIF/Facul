#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Simulação de Atendimento em Fila
// Implemente uma fila para simular um sistema de atendimento em uma loja. Cada cliente tem um tempo de chegada e um tempo de atendimento. 
// A fila deve processar os clientes por ordem de chegada e registrar o tempo de espera total de cada um.

// Funções:

// chegadaCliente(int tempoChegada, int tempoAtendimento): Insere um cliente com os tempos de chegada e atendimento na fila.
// processaFila(): Processa os clientes na fila, calculando o tempo total de espera de cada cliente.

typedef struct No {
    char nome[50];
    int tempoChegada;
    int tempoAtendimento;
    struct No *prox;
} No;

typedef struct {
    No *primeiro;
    No *ultimo;
} Fila;

void initLoja(Fila *l);
void ChegadaCliente(Fila *l, int tChegada, int tAtendimento, char *NomeCliente);
void processaFila(Fila *l);

int main() {
    Fila loja;
    initLoja(&loja);

    ChegadaCliente(&loja, 50, 60, "Yan");
    ChegadaCliente(&loja, 50, 60, "Ermerson");

    processaFila(&loja);
    return 0;
}


void initLoja(Fila *l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
}

void ChegadaCliente(Fila *l, int tChegada, int tAtendimento, char *NomeCliente) {
    No *cliente = (No*)malloc(sizeof(No));
    strcpy(cliente->nome, NomeCliente);
    cliente->tempoChegada = tChegada;
    cliente->tempoAtendimento = tAtendimento;
    cliente->prox = NULL;

    if (l->primeiro == NULL) {
        l->primeiro = cliente;
        l->ultimo = cliente;
    } else {
        l->ultimo->prox = cliente;
        l->ultimo = cliente;
    }
}

void processaFila(Fila *l) {
    No *clientes = l->primeiro;

    printf("\nAtendimento:\n");
    while (clientes != NULL) {
        printf("Cliente '%s' foi atendido em %d minuto(s)\n", clientes->nome, clientes->tempoAtendimento + clientes->tempoChegada);
        clientes = clientes->prox;
    }
    printf("Atendimento Finalizado!\n");
}