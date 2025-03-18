#include <stdlib.h>
#include "yanStack.h"

Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

void push(Stack *stack, int value) {
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->data = value;
    newElement->next = stack->top;
    stack->top = newElement;
    stack->size++;
}
int pop(Stack *stack) {
    Element *popedItem = stack->top;
    stack->top = stack->top->next;
    int poped = popedItem->data;
    free(popedItem);
    stack->size--;
    return poped;
}

int peek(Stack *stack) {
    return stack->top->data;
}

int size(Stack *stack) {
    return stack->size;
}