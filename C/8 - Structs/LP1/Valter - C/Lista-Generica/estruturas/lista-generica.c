#include "./lista-generica.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* initList(void) { return NULL; }

int isEmpty(Node* list) { return list == NULL; }

Node* freeList(Node* list) {
  while (list != NULL) {
    Node* releasedElement = list;
    list = list->next;
    free(releasedElement->info);
    free(releasedElement);
  }

  return NULL;
}

Node* listInsert(Node* list, void* info, Verify verify) {
  Node* newElement = (Node*)malloc(sizeof(Node));
  newElement->info = info;

  Node* temp = list;
  Node* prevElement = NULL;

  for (prevElement = NULL, temp = list; temp != NULL;
       prevElement = temp, temp = temp->next) {
    if (verify(temp->info, info) == 999) {
      return list;
    } else if (verify(temp->info, info)) {
      break;
    }
  }

  if (prevElement == NULL && temp == NULL) {
    newElement->next = NULL;
    list = newElement;
  } else if (prevElement != NULL && temp == NULL) {
    newElement->next = NULL;
    prevElement->next = newElement;
  } else if (prevElement == NULL && temp != NULL) {
    newElement->next = list;
    list = newElement;
  } else if (prevElement != NULL && temp != NULL) {
    prevElement->next = newElement;
    newElement->next = temp;
  }

  return list;
}

Node* listRemove(Node* list, void* info, Verify verify) {
  Node* temp = list;
  Node* prevElement = NULL;

  while (temp != NULL) {
    if (verify(temp->info, info)) break;
    prevElement = temp;
    temp = temp->next;
  }

  if (temp == NULL) return list;

  if (prevElement == NULL) {
    list = temp->next;
  } else {
    prevElement->next = temp->next;
  }

  free(temp->info);
  free(temp);

  return list;
}

void* listSearch(Node* list, void* info, Verify verify) {
  Node* temp = list;

  while (temp != NULL) {
    if (verify(temp->info, info)) return temp->info;

    temp = temp->next;
  }

  return NULL;
}

void listPrint(Node* list, Operation imprime) {
  Node* temp = list;

  while (temp != NULL) {
    imprime(temp->info);
    temp = temp->next;
  }
}

int listMap(Node* list, Operation operation, Filter filter) {
  Node* temp = list;

  while (temp != NULL) {
    if (filter(temp->info)) operation(temp->info);

    temp = temp->next;
  }

  return 1;
}

Node* listFileLoad(Node* list, char* fileName, ReadLine readline) {
  FILE* file = fopen(fileName, "r+");

  if (!file) {
    printf("Erro ao carregar arquivo: %s", fileName);
    exit(1);
  }

  char line[121];
  char chr = ' ';
  int i = 0;

  do {
    chr = fgetc(file);

    if (chr == '\n' || chr == EOF) {
      line[i] = '\0';

      if (i != 0) {
        Node* newElement = (Node*)malloc(sizeof(Node));

        newElement->info = readline(line);
        newElement->next = list;
        list = newElement;
        i = 0;
      }
    } else {
      line[i++] = chr;
    }

  } while (chr != EOF);

  fclose(file);

  return list;
}

int listFileSave(Node* list, char* fileName, WriteLine writeline) {
  FILE* file = fopen(fileName, "w+");
  Node* temp = list;

  if (!file) {
    printf("Erro ao carregar arquivo: %s", fileName);
    exit(1);
  }

  while (temp != NULL) {
    char* linha = writeline(temp->info);

    if (!linha) {
      fclose(file);
      return 0;
    }

    fprintf(file, linha);

    free(linha);

    temp = temp->next;
  }

  fclose(file);

  return 1;
}