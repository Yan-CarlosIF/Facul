#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void push(Stack *stack, int value) {
    Item *newItem = (Item*)malloc(sizeof(Item));

    newItem->value = value;
    newItem->next = stack->top;
    stack->top = newItem;

    stack->size++;
}

int pop(Stack *stack, int value) {
    if (value == stack->top->value) {
        Item *popedItem = stack->top;
        int returnedValue = popedItem->value;
        stack->top = stack->top->next;
        free(popedItem);
        stack->size--;
        return returnedValue;
    } else if (value == stack->top->next->value) {
        printf("Valor nao pode ser excluido!\n");
        return -1;
    } else {
        Item *aux = stack->top;
        
        while (aux->next != NULL) {
            if (aux->next->value == value) {
                Item *popedItem = aux->next;
                int returnedValue = popedItem->value;
                aux->next = aux->next->next;
                free(popedItem);
                return returnedValue;
            }
            aux = aux->next;
        }
    }

    return -1;
}

void displayStack(Stack *stack) {
    Item *aux = stack->top;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}