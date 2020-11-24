#ifndef helper_h
#define helper_h

#include "../../print.h"

TreeNode* treeSearch(TreeNode* x, int k) {
  if (x == nullptr || k == x->key)
    return x;
  if (k < x->key)
    return treeSearch(x->left, k);
  else
    return treeSearch(x->right, k);
}

TreeNode* treeMinimum(TreeNode* x) {
  while (x->left != nullptr)
    x = x->left;
  return x;
}

TreeNode* treeMaximum(TreeNode* x) {
  while (x->right != nullptr)
    x = x->right;
  return x;
}

void inorderTreeWalk(TreeNode*& x) {
  if (x != nullptr) {
    inorderTreeWalk(x->left);
    print(x->key);
    inorderTreeWalk(x->right);
  }
}

void preorderTreeWalk(TreeNode*& x) {
  if (x != nullptr) {
    print(x->key);
    preorderTreeWalk(x->left);
    preorderTreeWalk(x->right);
  }
}

void postorderTreeWalk(TreeNode*& x) {
  if (x != nullptr) {
    postorderTreeWalk(x->left);
    postorderTreeWalk(x->right);
    print(x->key);
  }
}

#endif