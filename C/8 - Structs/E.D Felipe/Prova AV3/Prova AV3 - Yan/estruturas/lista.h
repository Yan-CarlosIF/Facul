#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

/** struct No
 *
 * Instancia um novo nó
 *
 * Attr:
 *     - value (int): valor inteiro do nó
 *     - *next (struct No *): ponteiro para o proximo
 *     - *prev (struct No *): ponteiro para o anterior
 */
typedef struct No {
  int value;
  struct No *next;
  struct No *prev;
} No;

/** struct DoublyLinkedList (ListaDuplamenteEncadeada, 'procurei no google esse nome em inglês kkkkk')
 *
 * Instancia um nova lista
 *
 * Attr:
 *     - *next (No *): ponteiro para o inicio da lista
 *     - *prev (No *): ponteiro para o fim da lista
 *     - size (int): tamanho da lista
 */
typedef struct {
  No *head;
  No *tail;
  int size;
} DoublyLinkedList;

// documentação das funções no arquivo lista.c
DoublyLinkedList *initList();
No *createNode(int value);
void push(DoublyLinkedList *list, int value);
void add(DoublyLinkedList *list, int value, int index);
int del(DoublyLinkedList *list, int index);
void printList(DoublyLinkedList *list, bool inicioAoFim);
void freeList(DoublyLinkedList *list);
#endif
