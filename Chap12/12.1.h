#ifndef ch12_1_h
#define ch12_1_h

#include <stack>
#include "../print.h"
#include "Node.h"

using std::stack;

// [Page 288]
//   INORDER-TREE-WALK(x)
//   - Time : O(n)
//
// [Page 289][12.1-3]
//   ITERATIVE-INORDER-TREE-WALK-WITH-STACK(x)
//   - Time : O(n)
//   - Space : O(n)
//
//   ITERATIVE-INORDER-TREE-WALK-WITHOUT-STACK(x)
//   - Time : O(n)
//   - Space complextiy: O(1)
//
// [Page 289][12.1-4]
//   PREORDER-TREE-WALK
//   - Time : O(n)
//
//   POSTORDER-TREE-WALK
//   - Time : O(n)

namespace CLRS {
namespace CH12 {
void inorderTreeWalk(Node* x) {
  if (x != nullptr) {
    inorderTreeWalk(x->left);
    print(x->key);
    inorderTreeWalk(x->right);
  }
}

void iterativeInorderTreeWalkWithStack(Node* x) {
  stack<Node*> stack;
  Node* curr = x;
  while (curr || !stack.empty()) {
    while (curr) {
      stack.push(curr);
      curr = curr->left;
    }
    curr = stack.top();
    stack.pop();
    print(curr->key);
    curr = curr->right;
  }
}

void iterativeInorderTreeWalkWithoutStack(Node* x) {
  if (x == nullptr) return;

  Node* curr = x;
  while (curr) {
    if (!curr->left) {
      print(curr->key);
      curr = curr->right;
    } else {
      // Be careful that we couldn't use
      // "Node* pred = treePredecessor(curr);" to find our predecessor,
      // because some nodes' right pointers have been modified. Therefore, the
      // "Node* treeMaximum(Node* x)" is broken now.
      Node* pred = curr->left;
      while (pred->right && pred->right != curr) pred = pred->right;
      if (pred->right) {
        pred->right = nullptr;
        print(curr->key);
        curr = curr->right;
      } else {
        pred->right = curr;
        curr = curr->left;
      }
    }
  }
}

void preorderTreeWalk(Node* x) {
  if (x != nullptr) {
    print(x->key);
    preorderTreeWalk(x->left);
    preorderTreeWalk(x->right);
  }
}

void postorderTreeWalk(Node* x) {
  if (x != nullptr) {
    postorderTreeWalk(x->left);
    postorderTreeWalk(x->right);
    print(x->key);
  }
}
}  // namespace CH12
}  // namespace CLRS

#endif