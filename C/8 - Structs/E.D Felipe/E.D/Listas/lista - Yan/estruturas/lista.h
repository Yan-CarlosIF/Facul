#ifndef LISTA_H
#define LISTA_H

typedef struct No {
  int value;
  struct No *next;
} No;

typedef struct {
  No *head;
  No *tail;
  int size;
} LinkedList;

LinkedList *initList();
No *createNode(int value);
void push(LinkedList *list, int value);
void add(LinkedList *list, int value, int index);
No *get(LinkedList *list, int index);
void set(LinkedList *list, int index, int value);
int pop(LinkedList *list);
int del(LinkedList *list, int index);
void sort(LinkedList *list);
void printList(LinkedList *list);
void freeList(LinkedList *list);
LinkedList *copy(LinkedList *list, const int start, const int end);
#endif
