#include "12.2.h"
#include "BST.h"

// [Page 294]
//   TREE-INSERT(T, z)
//   - Time : O(lg n)
//
// [Page 296]
//   TRANSPLANT(T, u, v)
//   - Time : O(1)
//
// [Page 298]
//   TREE-DELETE(T, z)
//   - Time : O(lg n)
//
// [Page 299][12.3-1]
//   RECURSIVE-TREE-INSERT(T, z)
//   - Time: O(lg n)

namespace CLRS {
namespace CH12 {
void treeInsert(BST& T, TreeNode* z) {
  TreeNode* y = new TreeNode(0);
  TreeNode* x = T.root;
  while (x != nullptr) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  z->p = y;
  if (y == nullptr)
    T.root = z;  // tree T was empty
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

void transplant(BST& T, TreeNode* u, TreeNode* v) {
  if (u->p == nullptr)
    T.root = v;
  else if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  if (v != nullptr)
    v->p = u->p;
}

void treeDelete(BST& T, TreeNode* z) {
  if (z->left == nullptr)
    transplant(T, z, z->right);
  else if (z->right == nullptr)
    transplant(T, z, z->left);
  else {
    TreeNode* y = treeMinimum(z->right);
    if (y->p != z) {
      transplant(T, y, y->right);
      y->right = z->right;
      y->right->p = y;
    }
    transplant(T, z, y);
    y->left = z->left;
    y->left->p = y;
  }
}

void recursiveTreeInsert(TreeNode*& root, TreeNode* z) {
  if (root == nullptr) {
    root = z;
    return;
  }
  z->p = root;
  if (z->key < root->key)
    recursiveTreeInsert(root->left, z);
  else
    recursiveTreeInsert(root->right, z);
}
}  // namespace CH12
}  // namespace CLRS
