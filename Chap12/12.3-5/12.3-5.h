#include "BST.h"
#include "helper.h"

// [Page 299][12.3-5]
//   PARENT(T, x)
//   - Time: O(lg n)
//
//   TREE-INSERT(T, z)
//   - Time: O(lg n)
//
//   TRANSPLANT(T, u, v)
//   - Time: O(lg n)
//
//   TREE-PREDECESSOR(T, x)
//   - Time: O(lg n)
//
//   TREE-DELETE(T, z)
//   - Time: O(lg n)

namespace CLRS {
namespace CH12 {
Node* parent(BST& T, Node* x) {
  if (x == T.root) return nullptr;
  Node* y = treeMaximum(x)->succ;
  if (y == nullptr) {
    y = T.root;
  } else {
    if (y->left == x) return y;
    y = y->left;
  }
  while (y->right != x) y = y->right;
  return y;
}

void treeInsert(BST& T, Node* z) {
  Node* y = new Node(0);
  Node* x = T.root;
  Node* pred = new Node(0);
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      pred = x;
      x = x->right;
    }
  }
  if (y == nullptr) {
    T.root = z;
    z->succ = nullptr;
  } else if (z->key < y->key) {
    y->left = z;
    z->succ = y;
    if (pred != nullptr) pred->succ = z;
  } else {
    y->right = z;
    z->succ = y->succ;
    y->succ = z;
  }
}

void transplant(BST& T, Node* u, Node* v) {
  Node* p = parent(T, u);
  if (p == nullptr)
    T.root = v;
  else if (u == p->left)
    p->left = v;
  else
    p->right = v;
}

Node* treePredecessor(BST& T, Node* x) {
  if (x->left != nullptr) return treeMaximum(x->left);
  Node* y = parent(T, x);
  while (y != nullptr && x == y->left) {
    x = y;
    y = parent(T, y);
  }
  return y;
}

void treeDelete(BST& T, Node* z) {
  // Find the node, whose succ is z, then replace that node's succ with z.succ
  Node* pred = treePredecessor(T, z);
  pred->succ = z->succ;
  if (z->left == nullptr)
    transplant(T, z, z->right);
  else if (z->right == nullptr)
    transplant(T, z, z->left);
  else {
    Node* y = treeMinimum(z->right);
    if (parent(T, y) != z) {
      transplant(T, y, y->right);
      y->right = z->right;
    }
    transplant(T, z, y);
    y->left = z->left;
  }
}
}  // namespace CH12
}  // namespace CLRS
