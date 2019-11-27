#include "Node.h"

// [Page 290]
//   TREE-SEARCH(x, k)
//   - Time: O(lg n)
//
// [Page 291]
//   ITERATIVE-TREE-SEARCH(x, k)
//   - Time: O(lg n)
//
//   TREE-MINIMUM(x)
//   - Time: O(lg n)
//
//   TREE-MAXIMUM(x)
//   - Time: O(lg n)
//
// [Page 292]
//   TREE-SUCCESSOR(x)
//   - Time: O(lg n)
//
// [Page 293][12.2-2]
//   RECURSIVE-TREE-MIMIMUM(x)
//   - Time: O(lg n)
//
//   RECURSIVE-TREE-MAXIMUM(x)
//   - Time: O(lg n)
//
// [Page 293][12.2-3]
//   TREE-PREDECESSOR(x)
//   - Time: O(lg n)

namespace CLRS {
namespace CH12 {
Node* treeSearch(Node* x, int k) {
  if (x == nullptr || k == x->key) return x;
  if (k < x->key)
    return treeSearch(x->left, k);
  else
    return treeSearch(x->right, k);
}

Node* iterateTreeSearch(Node* x, int k) {
  while (x != nullptr && k != x->key) {
    if (k < x->key)
      x = x->left;
    else
      x = x->right;
  }
  return x;
}

Node* treeMinimum(Node* x) {
  while (x->left != nullptr) x = x->left;
  return x;
}

Node* treeMaximum(Node* x) {
  while (x->right != nullptr) x = x->right;
  return x;
}

Node* treeSuccessor(Node* x) {
  if (x->right != nullptr) return treeMinimum(x->right);
  Node* y = x->p;
  while (y != nullptr && x == y->right) {
    x = y;
    y = y->p;
  }
  return y;
}

Node* recursiveTreeMinimum(Node* x) {
  if (x->left != nullptr)
    return recursiveTreeMinimum(x->left);
  else
    return x;
}

Node* recursiveTreeMaximum(Node* x) {
  if (x->right != nullptr)
    return recursiveTreeMaximum(x->right);
  else
    return x;
}

Node* treePredecessor(Node* x) {
  if (x->left != nullptr) return treeMaximum(x->left);
  Node* y = x->p;
  while (y != nullptr && x == y->left) {
    x = y;
    y = y->p;
  }
  return y;
}
}  // namespace CH12
}  // namespace CLRS
