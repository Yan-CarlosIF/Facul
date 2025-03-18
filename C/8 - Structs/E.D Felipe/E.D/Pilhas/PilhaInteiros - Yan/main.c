#include <stdio.h>
#include "pilha.h"
#include "pilha.c"

int main() {
    Pilha *stack = inicializarPilha();

    if (isEmpty(stack)) {
        printf("Pilha esta vazia!\n"); 
    }

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    int popedItem = pop(stack);
    printf("Item Popado: %d\n", popedItem);
    printf("Ultimo item: %d\n", peek(stack));

    if (isEmpty(stack)) {
        printf("Pilha esta vazia!\n"); 
    }
    
    return 0;
}