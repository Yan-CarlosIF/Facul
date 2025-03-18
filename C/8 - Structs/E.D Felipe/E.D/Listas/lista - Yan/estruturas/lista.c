#include "./lista.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *initList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (list == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

No *createNode(int value) {
  No *node = (No *)malloc(sizeof(No));
  if (node == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  node->value = value;
  node->next = NULL;

  return node;
}

void push(LinkedList *list, int value) {
  No *newNode = createNode(value);

  if (list->size == 0) {
    list->head = list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;
}

void add(LinkedList *list, int value, int index) {
  if (index < 0 || index > list->size) return;

  No *newNode = createNode(value);

  if (index == 0) {
    newNode->next = list->head;
    list->head = newNode;

    if (list->size == 0) list->tail = list->head;
  } else {
    No *temp = list->head;

    for (int i = 0; i < index - 1; i++) temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    if (index == list->size) list->tail = newNode;
  }

  list->size++;
}

No *get(LinkedList *list, int index) {
  if (list->size == 0 || index >= list->size || index < 0) return NULL;

  No *temp = list->head;

  for (int i = 0; i < index; i++) temp = temp->next;
  return temp;
}

void set(LinkedList *list, int index, int value) {
  No *node = get(list, index);

  if (node != NULL) node->value = value;
}

int pop(LinkedList *list) {
  if (list->size == 0) return -1;

  No *temp = list->head;
  int value;

  if (list->size == 1) {
    value = temp->value;
    list->head = list->tail = NULL;
  } else {
    while (temp->next != list->tail) temp = temp->next;

    value = list->tail->value;
    free(list->tail);
    list->tail = temp;
    temp->next = NULL;
  }

  list->size--;
  return value;
}

int del(LinkedList *list, int index) {
  if (list->size == 0 || index < 0 || index >= list->size) return -1;

  No *deleted;

  if (index == 0) {
    deleted = list->head;
    list->head = list->head->next;
    if (list->head == NULL) list->tail = NULL;
  } else {
    No *temp = list->head;

    for (int i = 0; i < index - 1; i++) temp = temp->next;

    deleted = temp->next;
    temp->next = deleted->next;
    if (index == list->size - 1) list->tail = temp;
  }

  int value = deleted->value;
  free(deleted);
  list->size--;
  return value;
}

void sort(LinkedList *list) {
  if (list->size == 0) return;

  No *atual = list->head, *sortedList = NULL;

  while (atual != NULL) {
    No *prox = atual->next;

    if (sortedList == NULL || sortedList->value >= atual->value) {
      atual->next = sortedList;
      sortedList = atual;
    } else {
      No *temp = sortedList;

      while (temp->next != NULL && temp->next->value < atual->value)
        temp = temp->next;

      atual->next = temp->next;
      temp->next = atual;
    }
    atual = prox;
  }

  No *temp = sortedList;
  while (temp->next != NULL) temp = temp->next;
  list->head = sortedList;
  list->tail = temp;
}

void printList(LinkedList *list) {
  if (list->size == 0) {
    printf("\nLista esta vazia!\n");
    return;
  }

  No *temp = list->head;
  // printf("\nLista Encadeada: ");
  while (temp != NULL) {
    printf("%d -> ", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}

void freeList(LinkedList *list) {
  if (list->size == 0) return;

  No *temp = list->head;
  while (temp != NULL) {
    No *deleted = temp;
    temp = temp->next;
    free(deleted);
  }

  free(list);
}

LinkedList *copy(LinkedList *list, const int start, const int end) {
  if (start < 0 || end >= list->size || start > end) return NULL;

  LinkedList *newList = initList();
  for (int i = start; i <= end; i++) push(newList, get(list, i)->value);
  return newList;
}
