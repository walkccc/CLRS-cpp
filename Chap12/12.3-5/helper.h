#ifndef helper_h
#define helper_h

#include "../../print.h"

Node* treeSearch(Node* x, int k) {
  if (x == nullptr || k == x->key) return x;
  if (k < x->key)
    return treeSearch(x->left, k);
  else
    return treeSearch(x->right, k);
}

Node* treeMinimum(Node* x) {
  while (x->left != nullptr) x = x->left;
  return x;
}

Node* treeMaximum(Node* x) {
  while (x->right != nullptr) x = x->right;
  return x;
}

void inorderTreeWalk(Node*& x) {
  if (x != nullptr) {
    inorderTreeWalk(x->left);
    print(x->key);
    inorderTreeWalk(x->right);
  }
}

void preorderTreeWalk(Node*& x) {
  if (x != nullptr) {
    print(x->key);
    preorderTreeWalk(x->left);
    preorderTreeWalk(x->right);
  }
}

void postorderTreeWalk(Node*& x) {
  if (x != nullptr) {
    postorderTreeWalk(x->left);
    postorderTreeWalk(x->right);
    print(x->key);
  }
}

#endif