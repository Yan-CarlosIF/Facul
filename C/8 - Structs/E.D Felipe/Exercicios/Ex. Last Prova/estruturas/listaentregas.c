#include "listaentregas.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
  int op;

  printf("0 - Sair\n");
  printf("1 - Adicionar\n");
  printf("2 - Remover\n");
  printf("3 - Atualizar\n");
  printf("4 - Buscar\n");
  printf("5 - Ordenar\n");
  printf("6 - Imprimir\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &op);
  getchar();

  return op;
}

int receberIndice(char *tipo) {
  int index;
  printf("Digite o indice que deseja %s: ", tipo);
  scanf("%d", &index);
  printf("\n");
  return index;
}

Entregas *initList() {
  Entregas *novaLista = (Entregas *)malloc(sizeof(Entregas));
  if (novaLista == NULL) {
    printf("ERRO: Falha ao alocar memória!\n");
    exit(1);
  }

  novaLista->head = NULL;
  novaLista->tail = NULL;
  novaLista->size = 0;

  return novaLista;
}

Entrega *createProd(int id, char *nome, char *end) {
  Entrega *novaEntrega = (Entrega *)malloc(sizeof(Entrega));
  if (novaEntrega == NULL) {
    printf("ERRO: Falha ao alocar memória!\n");
    exit(1);
  }

  novaEntrega->id = id;
  strcpy(novaEntrega->endereco, end);
  strcpy(novaEntrega->nomeDestinatario, nome);
  novaEntrega->next = NULL;

  return novaEntrega;
}

void add(Entregas *list, int index, Entrega entrega) {
  if (index < 0 || index > list->size) {
    printf("Indice Invalido!\n\n");
    return;
  }

  Entrega *novaEntrega =
      createProd(entrega.id, entrega.nomeDestinatario, entrega.endereco);

  if (index == 0) {
    novaEntrega->next = list->head;
    list->head = novaEntrega;

    if (list->size == 0) list->tail = list->head;
  } else if (index == list->size) {
    list->tail->next = novaEntrega;
    list->tail = novaEntrega;
  } else {
    Entrega *temp = list->head;

    for (int i = 0; i < index - 1; i++) temp = temp->next;

    novaEntrega->next = temp->next;
    temp->next = novaEntrega;
  }

  list->size++;
}

Entrega *get(Entregas *list, int index) {
  if (index < 0 || index >= list->size || list->size == 0) return NULL;

  if (index == 0) {
    return list->head;
  } else if (index == list->size - 1) {
    return list->tail;
  } else {
    Entrega *temp = list->head;

    for (int i = 0; i < index; i++) temp = temp->next;

    return temp;
  }
}

void set(Entregas *list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Indice Invalido!\n\n");
    return;
  }

  Entrega *entrega = list->head;

  for (int i = 0; i < index; i++) entrega = entrega->next;

  int op;
  do {
    printf("\nQual informacao voce deseja alterar?\n");
    printf("0 - sair\n1 - nome\n2 - endereco\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    getchar();
    char novaInfo[50];

    switch (op) {
      case 0:
        printf("\nSaindo...\n\n");
        break;
      case 1:
        printf("\nDigite o novo nome:");
        fgets(novaInfo, 50, stdin);
        novaInfo[strcspn(novaInfo, "\n")] = '\0';

        strcpy(entrega->nomeDestinatario, novaInfo);
        break;
      case 2:
        printf("\nDigite o novo endereco:");
        fgets(novaInfo, 50, stdin);
        novaInfo[strcspn(novaInfo, "\n")] = '\0';

        strcpy(entrega->endereco, novaInfo);
        break;
      default:
        printf("\nOpcao Invalida!\n");
        break;
    }
  } while (op != 0);
}

void del(Entregas *list, int index) {
  if (index < 0 || index >= list->size || list->size == 0) {
    printf("Indice Invalido!\n\n");
    return;
  }

  Entrega *deleted;

  if (index == 0) {
    deleted = list->head;
    list->head = list->head->next;
    free(deleted);
    list->size--;
    return;
  }

  Entrega *temp = list->head;
  if (index == list->size - 1) {
    while (temp->next != list->tail) temp = temp->next;

    deleted = list->tail;
    temp->next = NULL;
    list->tail = temp;
  } else {
    for (int i = 0; i < index - 1; i++) temp = temp->next;

    deleted = temp->next;
    temp->next = deleted->next;
  }

  free(deleted);
  list->size--;
}

void sort(Entregas *list) {
  if (list->size == 0) {
    printf("\nNao e possivel ordenar uma lista vazia!\n\n");
    return;
  }

  Entrega *atual = list->head, *sorted = NULL;

  while (atual != NULL) {
    Entrega *prox = atual->next;

    if (sorted == NULL || tolower(sorted->nomeDestinatario[0]) >=
                          tolower(atual->nomeDestinatario[0])) {
      atual->next = sorted;
      sorted = atual;
    } else {
      Entrega *temp = sorted;

      while (temp->next != NULL && tolower(temp->next->nomeDestinatario[0]) <
                                   tolower(atual->nomeDestinatario[0]))
        temp = temp->next;

      atual->next = temp->next;
      temp->next = atual;
    }
    atual = prox;
  }

  Entrega *temp = sorted;
  while (temp->next != NULL) temp = temp->next;
  list->head = sorted;
  list->tail = temp;
  printf("\nLista de entregas em ordem alfabetica!\n\n");
}

void printList(Entregas *list) {
  if (list->size == 0) {
    printf("\nLista esta vazia!\n\n");
    return;
  }

  Entrega *temp = list->head;
  printf("\nLista de Entregas: ");
  printf("\n\nID - NOME - ENDERECO\n");
  while (temp != NULL) {
    printf("\n%d - %s - %s\n", temp->id, temp->nomeDestinatario,
           temp->endereco);
    temp = temp->next;
  }
  printf("\n");
}

void freeList(Entregas *list) {
  if (list->size == 0) return;

  Entrega *temp = list->head;
  while (temp != NULL) {
    Entrega *deleted = temp;
    temp = temp->next;
    free(deleted);
  }

  free(list);
}