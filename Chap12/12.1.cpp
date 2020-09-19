#include "12.1.h"

#include "../print.h"

using namespace CLRS::CH12;

int main() {
  print(string("Chapter 12.1 What is a binary search tree?"));

  cout << "Initialize a binary search tree (root) as Figure 12.1 (a)\n";
  // Initialize the BST
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(7);
  root->right->right = new TreeNode(8);

  // Connect the parent pointers
  root->left->p = root;
  root->left->left->p = root->left;
  root->left->right->p = root->left;
  root->right->p = root;
  root->right->right->p = root->right;
  cout << "      6" << endl
       << "     / \\" << endl
       << "    5   7" << endl
       << "   / \\   \\" << endl
       << "  2   5   8";

  cout << "\n\nRECURSIVE-INORDER-TREE-WALK(root)\n";
  inorderTreeWalk(root);

  cout << "\n\nITERATIVE-INORDER-TREE-WALK-WITH-STACK(root)\n";
  iterativeInorderTreeWalkWithStack(root);

  cout << "\n\nITERATIVE-INORDER-TREE-WALK-WITHOUT-STACK(root)\n";
  iterativeInorderTreeWalkWithoutStack(root);

  cout << "\n\nRECURSIVE-PREORDER-TREE-WALK(root)\n";
  preorderTreeWalk(root);

  cout << "\n\nRECURSIVE-POSTORDER-TREE-WALK(root)\n";
  postorderTreeWalk(root);
}