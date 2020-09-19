#include "TreeNode.h"

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
TreeNode* treeSearch(TreeNode* x, int k) {
  if (x == nullptr || k == x->key) return x;
  if (k < x->key)
    return treeSearch(x->left, k);
  else
    return treeSearch(x->right, k);
}

TreeNode* iterateTreeSearch(TreeNode* x, int k) {
  while (x != nullptr && k != x->key) {
    if (k < x->key)
      x = x->left;
    else
      x = x->right;
  }
  return x;
}

TreeNode* treeMinimum(TreeNode* x) {
  while (x->left != nullptr) x = x->left;
  return x;
}

TreeNode* treeMaximum(TreeNode* x) {
  while (x->right != nullptr) x = x->right;
  return x;
}

TreeNode* treeSuccessor(TreeNode* x) {
  if (x->right != nullptr) return treeMinimum(x->right);
  TreeNode* y = x->p;
  while (y != nullptr && x == y->right) {
    x = y;
    y = y->p;
  }
  return y;
}

TreeNode* recursiveTreeMinimum(TreeNode* x) {
  if (x->left != nullptr)
    return recursiveTreeMinimum(x->left);
  else
    return x;
}

TreeNode* recursiveTreeMaximum(TreeNode* x) {
  if (x->right != nullptr)
    return recursiveTreeMaximum(x->right);
  else
    return x;
}

TreeNode* treePredecessor(TreeNode* x) {
  if (x->left != nullptr) return treeMaximum(x->left);
  TreeNode* y = x->p;
  while (y != nullptr && x == y->left) {
    x = y;
    y = y->p;
  }
  return y;
}
}  // namespace CH12
}  // namespace CLRS
