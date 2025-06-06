#include <string.h>

#include "TAD_TREE.h"

typedef struct Pessoa {
  int id;
  char name[100];
} Pessoa;

int compare_ids(void* a, void* b) {
  return ((Pessoa*)a)->id < ((Pessoa*)b)->id;
}

void print_pessoa(void* pessoa) { printf("Id: %d\n", ((Pessoa*)pessoa)->id); }

void dobrar_id(void* pessoa) {
    printf("Id: %d * 2 = %d\n", ((Pessoa*)pessoa)->id, ((Pessoa*)pessoa)->id * 2);
}

int main(void) {
  Node* tree = tree_create_empty();
  Node* balanced_tree = tree_create_empty();

  Pessoa pessoas[] = {
      {10, "Yan"},
      {30, "Valter"},
      {20, "Joao"},
      {15, "Marcos"},
  };

  for (int i = 0; i < 4; i++) {
    Node* n1 = tree_create_node(&pessoas[i], NULL, NULL);
    Node* n2 = tree_create_node(&pessoas[i], NULL, NULL);

    tree = tree_insert_node(tree, n1, compare_ids);
    balanced_tree = tree_insert_balanced(balanced_tree, n2, compare_ids);
  }

  printf("\nArvore sem balanceamento\n\n");
  tree_print(tree, print_pessoa, 0);

  printf("\nArvore com balanceamento\n\n");
  tree_print(balanced_tree, print_pessoa, 0);

  tree_map(balanced_tree, dobrar_id);

  return 0;
}