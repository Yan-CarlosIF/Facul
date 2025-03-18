#ifndef ARV_H
#define ARV_H

typedef struct Node {
  int value;
  struct Node *left, *right;
} Node;

typedef struct {
  Node *root;
  int size;
} Tree;

Tree *initBinaryTree();
Node *createNode(int value);
void insert(Tree *tree, int value);
void insertNode(Node *root, int value);
void printBinaryTree(Tree *tree);
void freeBinaryTree(Tree *tree);
#endif