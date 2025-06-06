#include "TAD_TREE.h"

#include <stdio.h>
#include <stdlib.h>

/* IS IT EMPTY?
    Return
        True if the tree is empty, otherwise false.
*/
int tree_empty(Node* root) { return root == NULL; }

/* CREATE AN ENPTY TREE
    Return
        (Node*)NULL, representing a empty tree.
*/
Node* tree_create_empty() { return (Node*)NULL; }

/* CREATE A NODE
    Creates a node with an info ans left and right sub-tree.
    Return
        pointer to a new node (Node*).
*/
Node* tree_create_node(void* info, Node* lst, Node* rst) {
  Node* new_node = (Node*)malloc(sizeof(Node));

  new_node->info = info;
  new_node->lst = lst;
  new_node->rst = rst;

  return new_node;
}

/* INSERT A NODE
    Inserts a node in a tree based on a comparison.
    If it's true, the new_node will be placed in the left sub-tree,
    if it's false, the new_node will be in the right sub-tree.
    Return
        True if the new_node was placed in the tree,
        otherwise false.
*/
Node* tree_insert_node(Node* root, Node* new_node, int(compare)(void*, void*)) {
  if (tree_empty(root)) return new_node;

  if (compare(new_node->info, root->info)) {
    root->lst = tree_insert_node(root->lst, new_node, compare);
  } else {
    root->rst = tree_insert_node(root->rst, new_node, compare);
  }

  return root;
}
/* FREE A TREE
    free memory of all elements in a tree/subtree starting from the "root" node.
*/
void tree_free(Node* root) {
  if (tree_empty(root)) return;

  tree_free(root->lst);
  tree_free(root->rst);
  free(root);
}

/* PERFORM OPERATION IN A TREE
    perform an operation in all elements of a tree.
*/
void tree_map(Node* root, void(operation)(void*)) {
    if (tree_empty(root)) return;

    operation(root->info);
    tree_map(root->lst, operation);
    tree_map(root->rst, operation);
}

/* INSERT ALL ELEMENTS IN A TREE
  insert all elements in a tree/subtree starting from the "root" node.
*/
void insert_all(Node* source, Node** dest, Node*(copy_node)(void*),
                int(compare)(void*, void*)) {
  // Condição de parada, caso a arvore seja vazia ou chegue ao fim
  if (tree_empty(source)) return;

  // Copia o nó
  Node* copied_node = copy_node(source->info);

  // Insere o nó copiado na arvore na arvore de destino
  *dest = tree_insert_balanced(*dest, copied_node, compare);

  // Chamada recursiva para o filho esquerdo
  insert_all(source->lst, dest, copy_node, compare);

  // Chamada recursiva para o filho direito
  insert_all(source->rst, dest, copy_node, compare);
}

/* FILTER ELEMENTS IN THE TREE
 Gather together a set of elements that satisfy condition inside the tree.
 Return
    Pointer to the root of a tree composed by the elements
    that satisfy the condition.
*/
Node* tree_filter(Node* root, int(condition)(void*), Node*(copy_node)(void*),
                  int(compare)(void*, void*)) {
  // Se a arvore for vazia, retorna uma arvore vazia
  if (tree_empty(root)) return tree_create_empty();

  // Cria uma nova arvore para armazenar os elementos filtrados
  Node* filtered_tree = tree_create_empty();

  // Verifica se o elemento atual satisfaz a condicao, se sim
  // copia ele e insere na nova arvore
  if (condition(root->info)) {
    Node* copied_node = copy_node(root->info);
    filtered_tree = tree_insert_balanced(filtered_tree, copied_node, compare);
  }

  // Filtra recursivamente os nós da subárvore esquerda e direita
  Node* left_filtered = tree_filter(root->lst, condition, copy_node, compare);
  Node* right_filtered = tree_filter(root->rst, condition, copy_node, compare);

  // Insere todos os nós filtrados da esquerda e da direita na nova árvore
  insert_all(left_filtered, &filtered_tree, copy_node, compare);
  insert_all(right_filtered, &filtered_tree, copy_node, compare);

  return filtered_tree;
}

/* SEARH AN ELEMENT IN THE TREE
 Search the first element that satisfy condition inside the tree.
 Return
    A pointer (Node*) to the first node that satisfied the conditino.
*/
Node* tree_search(Node* root, int(condition)(void*)) {
    if (tree_empty(root)) return NULL;

    if (condition(root->info)) return root;

    Node* found_in_left = tree_search(root->lst, condition);
    if (found_in_left) return found_in_left;
    
    return tree_search(root->rst, condition);
}

/* PRINT THE ELEMENTS OF THE TREE
 Shows the elements of the tree as if it were lying down, elements of the right
 going up and the elements of the left going down
 */
void tree_print(Node* root, void(print)(void*), int depth) {
  if (tree_empty(root)) return;

  tree_print(root->rst, print, depth + 1);

  // Indentação proporcional à profundidade
  for (int i = 0; i < depth; i++) {
    printf("       ");
  }
  print(root->info);

  tree_print(root->lst, print, depth + 1);
}

/* VERIFIES THE HEIGHT OF THE NODE
 Receives a node that calculates his height on the tree
 Return
    An integer for the height
*/
int tree_get_height(Node* node) {
  if (tree_empty(node)) return -1;  // Altura de NULL é -1 (por convenção)

  int left_height = tree_get_height(node->lst);
  int right_height = tree_get_height(node->rst);

  return 1 + (left_height > right_height ? left_height : right_height);
}

/* ROTATES THE TREE TO THE RIGHT
 Executes a rotation to the right, to fix the imbalance
 when the left subtree is heavier
 Return
    A pointer (Node*) to the new root
*/
Node* rotate_right(Node* root) {
  Node* node_lst = root->lst;          // node_lst é o filho da esquerda de root
  Node* node_lst_rst = node_lst->rst;  // node_lst_rst é a subárvore a direita
                                       // de node_lst (filho esquerdo de root)

  node_lst->rst = root;  // a direita de node_lst agora aponta para root
  root->lst =
      node_lst_rst;  // a esquerda de root agora aponta para node_lst_rst
                     // (subárvore a direita do filho a esquerda de root)

  return node_lst;  // node_lst se torna a nova raiz do subárvore
}

/* ROTATES THE TREE TO THE LEFT
 Executes a rotation to the left, to fix the imbalance
 when the right subtree is heavier
 Return
    A pointer (Node*) to the new root
*/
Node* rotate_left(Node* root) {
  Node* node_rst = root->rst;          // node_rst é o filho a direita de root
  Node* node_rst_lst = node_rst->lst;  // node_rst_lst é a subárvore a esquerda
                                       // de node_rst (filho a direita de root)

  node_rst->lst = root;  // node_rst agora aponta para root
  root->rst =
      node_rst_lst;  // a direita de root agora aponta para node_rst_lst
                     // (subárvore a esquerda do filho a direita de root)

  return node_rst;  // node_lst se torna a nova raiz do subárvore
}

/* INSERTS A NEW NODE WHILE BALANCING THE TREE
 Inserts a new node like a BST, but balancing the tree
 after each insertion to keep it balanced
 Return
    A pointer (Node*) to the new root
*/
Node* tree_insert_balanced(Node* root, Node* new_node,
                           int(compare)(void*, void*)) {
  // Se a arvore estiver vazia, adiciona o novo nó na raiz
  if (tree_empty(root)) return new_node;

  // Insire o novo nó como uma BST normal
  if (compare(new_node->info, root->info)) {
    root->lst = tree_insert_balanced(root->lst, new_node, compare);
  } else {
    root->rst = tree_insert_balanced(root->rst, new_node, compare);
  }

  // Calcula o fator de balanceamento
  // balance_factor > 1: subárvore esquerda muito pesada
  // balance_factor < -1: subárvore direita muito pesada
  int balance_factor =
      root ? tree_get_height(root->lst) - tree_get_height(root->rst) : 0;

  // Caso Left Left
  if (balance_factor > 1 && compare(new_node->info, root->lst->info))
    return rotate_right(root);

  // Caso Right Right
  if (balance_factor < -1 && !compare(new_node->info, root->rst->info))
    return rotate_left(root);

  // Caso Left Right
  if (balance_factor > 1 && !compare(new_node->info, root->lst->info)) {
    root->lst = rotate_left(root->lst);
    return rotate_right(root);
  }

  // Caso Right Left
  if (balance_factor < -1 && compare(new_node->info, root->rst->info)) {
    root->rst = rotate_right(root->rst);
    return rotate_left(root);
  }

  return root;
}