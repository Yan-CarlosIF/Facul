#include "./lista.h"
#include <stdio.h>
#include <stdlib.h>

/** Função initList
 *
 * Aloca memória para uma nova lista
 * 
 * Return: um ponteiro para a lista criada
 */
DoublyLinkedList *initList() {
  // alocando memoria para uma lista
  DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
  // verificando se ocorreu um erro na alocação de memória
  if (list == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  // iniciando a lista com NULL e o tamanho com 0
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

/** Função createNode
 *
 * Aloca memória para um novo nó
 *
 * Args:
 *     - value (int): o valor do novo nó instanciado
 * 
 *  Return: um ponteiro para o nó criado
 */
No *createNode(int value) {
  // alocando memória para um novo nó
  No *node = (No *)malloc(sizeof(No));
  // verificando se ocorreu um erro na alocação de memória
  if (node == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  // iniciando o nó com o seu valor recebido na função e os ponteiro de prox e anterior com NULL
  node->value = value;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

/** Função push
 *
 * Adiciona um novo nó no fim da lista
 *
 * Args:
 *     - *list (DoublyLinkedList*): ponteiro para a lista que deseja adicionar um novo nó
 *     - value (int): o valor do novo nó adicionado
 */
void push(DoublyLinkedList *list, int value) {
  // criando um novo nó
  No *newNode = createNode(value);

  if (list->size == 0) {
    // se a lista estiver vazia o fim e o inicio serão iguais
    list->head = list->tail = newNode;
  } else {
    // se conter elementos, o anterior do novo elemento é igual a o ultimo elemento da lista
    // o proximo do ultimo elemento é o novo, e o fim passará ser o novo elemento 
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
  }

  // aumenta o tamanho da lista
  list->size++;
}

/** Função add
 *
 * Adiciona um nó da lista
 *
 * Args:
 *     - *list (DoublyLinkedList*): ponteiro para a lista que deseja fazer a exclusão de um nó
 *     - value (int): o valor o nó que deseja adicionar
 *     - index (int): o indice que deseja adicionar o nó 
 */
void add(DoublyLinkedList *list, int value, int index) {
  // verifica se o indice é valido
  if (index < 0 || index > list->size) return;

  // cria um novo nó
  No *newNode = createNode(value);

  // se o indice for 0 adiciona no início
  if (index == 0) {
    // se a lista não estiver vazia atualiza o anterior ao inicio atual
    if (list->head != NULL) list->head->prev = newNode;

    newNode->next = list->head;
    list->head = newNode;

    // se a lista estiver fazia o fim será o mesmo do início
    if (list->size == 0) list->tail = list->head;
    // adiciona no final da lista
  } else if (index == list->size) {
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
    // adiciona no meio da lista
  } else {
    No *temp = list->head;

    // percorre a lista até achar o elemento do indice
    for (int i = 0; i < index; i++) temp = temp->next;


    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
    newNode->next = temp;
  }

  // aumenta o tamanho da lista
  list->size++;
}

/** Função del
 *
 * Deleta um nó da lista
 *
 * Args:
 *     - *list (DoublyLinkedList*): ponteiro para a lista que deseja fazer a exclusão de um nó
 *     - index (int): o indice do nó que deseja excluir
 * 
 * Return: um inteiro que corresponde ao valor do nó excluido
 */
int del(DoublyLinkedList *list, int index) {
  // retorna -999 se o indice for inválido
  if (list->size == 0 || index < 0 || index >= list->size) return -999;

  // ponteiro para o nó a ser deletado
  No *deleted;

  // deleta o primeiro elemento a lista
  if (index == 0) {
    deleted = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    if (list->head == NULL) list->tail = NULL;
  // deleta o ultimo elemento da lista
  } else if (list->size == index - 1) {
    deleted = list->tail;
    // o fim da lista será o seu anterior
    list->tail = list->tail->prev;
    // o proximo do novo fim da lista será NULL
    list->tail->next = NULL;
  // deleta um elemento no meio da lista
  } else {
    No *temp = list->head;

    // percorre a lista até achar o elemento do indice
    for (int i = 0; i < index; i++) temp = temp->next;

    deleted = temp;
    // o proximo do anterior ao elemento deletado será o proximo do elemento deletado
    temp->prev->next = temp->next;
    // o anterior do proximo ao elemento deletado será o anterior do elemento deletado
    temp->next->prev = temp->prev;
  }

  // valor a ser retornado do item deletado
  int value = deleted->value;
  // libera memória do item deletado
  free(deleted);
  // diminui o tamanho da lista
  list->size--;
  return value;
}

/** Função printList
 *
 * Percorre toda a lista, exibindo seus itens, do inicio ao fim, ou do fim ao inicio
 *
 * Args:
 *     - *list (DoublyLinkedList*): ponteiro para a lista que deseja exibir
 *     - inicioAoFim (bool): booleana para escolher como deseja percorrer
 */
void printList(DoublyLinkedList *list, bool inicioAoFim) {
  // não faz nada se a lista estiver vazia
  if (list->size == 0) {
    printf("\nLista esta vazia!\n");
    return;
  }

  // se a booleana for true exibe os elementos do início ao fim
  if (inicioAoFim) {
    printf("\ninicio ao fim: ");
    No *temp = list->head;
    while (temp != NULL) {
      printf("%d -> ", temp->value);
      temp = temp->next;
    }
    printf("NULL\n");
  // se a booleana for false exibe os elementos do fim ao inicio
  } else {
    printf("\nfim ao inicio: ");
    No *temp = list->tail;
    while (temp != NULL) {
      printf("%d -> ", temp->value);
      temp = temp->prev;
    }
    printf("NULL\n");
  }
}


/** Função freeList
 *
 * Percorre toda a lista, liberando a memória alocada de cada nó e da propria lista
 *
 * Args:
 *     - *list (DoublyLinkedList*): ponteiro para a lista que deseja liberar memória
 */
void freeList(DoublyLinkedList *list) {
  // se a lista estiver vazia não faz nada
  if (list->size == 0) return;

  // percorre a lista liberando a memória de cada nó
  No *temp = list->head;
  while (temp != NULL) {
    No *deleted = temp;
    temp = temp->next;
    free(deleted);
  }

  // libera a memória da lista
  free(list);
}
