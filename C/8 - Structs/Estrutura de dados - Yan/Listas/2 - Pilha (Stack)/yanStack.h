#include <stdbool.h>
#ifndef YANSTACK_H
#define YANSTACK_H

typedef struct Element {
    int data;
    struct Element *next;
} Element;

typedef struct {
    Element *top;
    int size;
} Stack;

Stack* createStack();
bool isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int size(Stack *stack);
#endif