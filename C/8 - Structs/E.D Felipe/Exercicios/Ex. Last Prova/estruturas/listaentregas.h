#ifndef LISTA_ENTREGAS_H
#define LISTA_ENTREGAS_H

// Cada entrega contém um ID, um nome de destinatário e um endereço.
typedef struct Entrega {
  int id;
  char nomeDestinatario[50];
  char endereco[50];
  struct Entrega *next;
} Entrega;

typedef struct {
  Entrega *head;
  Entrega *tail;
  int size;
} Entregas;

int menu();
int receberIndice(char *tipo);
Entregas *initList();
Entrega *createProd(int id, char *nome, char *end);
void add(Entregas *list, int index, Entrega entrega);
Entrega *get(Entregas *list, int index);
void set(Entregas *list, int index);
void del(Entregas *list, int index);
void sort(Entregas *list);
void printList(Entregas *list);
void freeList(Entregas *list);
#endif
