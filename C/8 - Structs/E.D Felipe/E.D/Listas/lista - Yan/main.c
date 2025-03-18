#include "./estruturas/lista.c"

int main() {
  LinkedList *lista = initList();

  printList(lista);
  push(lista, 1);
  push(lista, 2);
  push(lista, 3);
  push(lista, 4);
  push(lista, 5);
  printf("Lista inicial apos push's: ");
  printList(lista);

  del(lista, 2);
  del(lista, 0);
  del(lista, 4);
  del(lista, 2);
  printf("\nLista depois dos deletes: ");
  printList(lista);

  add(lista, 3, 1);
  add(lista, 5, 3);
  add(lista, 1, 0);
  add(lista, 6, 5);
  printf("\nLista depois dos adds: ");
  printList(lista);

  printf("\ngetted: %d\n", get(lista, 3)->value);

  set(lista, 4, 10);
  pop(lista);
  set(lista, 4, 6);
  push(lista, 10);
  set(lista, 5, 7);

  printf("\nLista depois dos set e pop e push: ");
  printList(lista);

  set(lista, 0, 7);
  set(lista, 1, 6);
  set(lista, 2, 5);
  set(lista, 3, 4);
  set(lista, 4, 3);
  set(lista, 5, 2);
  printf("\nLista antes da ordenacao: ");
  printList(lista);

  sort(lista);
  printf("\nLista ordenada: ");
  printList(lista);

  LinkedList *novaLista = copy(lista, 1, 5);
  printf("\nCopia da lista: ");
  printList(novaLista);

  free(novaLista);
  freeList(lista);
}