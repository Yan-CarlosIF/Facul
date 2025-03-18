#include <stdio.h>
#include "estruturas/pilha/pilha.h"
#include "estruturas/pilha/pilha.c"

int main(void){
    PilhaInteiros *pilha = criarPilhaInteiros();
    printf("Tamanho: %d\n", tamanho(pilha));
    empilhar(10, pilha); // PUSH
    printf("Tamanho: %d\n", tamanho(pilha));
    empilhar(20, pilha);
    printf("Tamanho: %d\n", tamanho(pilha));
    empilhar(30, pilha);

    printf("Topo: %d\n", topo(pilha));

    printf("Tamanho: %d\n", tamanho(pilha));

    printf("Vazia: %d\n", vazia(pilha));

    printf("Desempilhando: %d\n", tirar(pilha)); // POP

    printf("Topo: %d\n", topo(pilha));

    printf("Tamanho: %d\n", tamanho(pilha));

    printf("Vazia: %d\n", vazia(pilha));
    return 0;
}