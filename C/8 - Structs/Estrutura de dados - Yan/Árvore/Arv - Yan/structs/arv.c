#include "arv.h"

#include <stdio.h>
#include <stdlib.h>

Tree *initBinaryTree() {
  Tree *newTree = (Tree *)malloc(sizeof(Tree));

  newTree->root = NULL;
  newTree->size = 0;

  return newTree;
}

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

Node *insertNode(Node *root, int value) {
  if (root == NULL) return createNode(value);

  if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertNode(root->right, value);
  }

  return root;
}

void insert(Tree *tree, int value) {
  tree->root = insertNode(tree->root, value);
  tree->size++;
}

