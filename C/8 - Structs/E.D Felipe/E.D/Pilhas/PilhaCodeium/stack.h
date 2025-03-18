#ifndef STACK_H
#define STACK_H

typedef struct Item {
    int value;
    struct Item *next;
} Item;

typedef struct {
    Item *top;
    int size;
} Stack;

void push(Stack *stack, int value);
int pop(Stack *Stack, int value);
void displayStack(Stack *stack);

#endif