#ifndef __TAD_LISTA_H__
#define __TAD_LISTA_H__

typedef struct Node {
  void* info;
  struct Node* next;
} Node;

typedef int (*Verify)(void*, void*);
typedef void (*Operation)(void*);
typedef int (*Filter)(void*);
typedef void* (*ReadLine)(char*);
typedef char* (*WriteLine)(void*);

Node* initList(void);
int isEmpty(Node* list);
Node* freeList(Node* list);
Node* listInsert(Node* list, void* info, Verify verify);
Node* listRemove(Node* list, void* info, Verify verify);
void* listSearch(Node* list, void* info, Verify verify);
void listPrint(Node* list, Operation imprime);
int listMap(Node* list, Operation operation, Filter filter);
Node* listFileLoad(Node* list, char* fileName, ReadLine readline);
int listFileSave(Node* list, char* fileName, WriteLine writeline);

#endif