#include "stack.c"
#include <stdio.h>

int main() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    displayStack(stack);
    pop(stack, 2);
    displayStack(stack);
    pop(stack, 1);
    displayStack(stack);
    pop(stack, 3);
    displayStack(stack);
    return 0;
}