#include "12.3-5.h"

using namespace CLRS::CH12;

void traversal(BST& T) {
  cout << "\nINORDER-TREE-WALK(T.root): ";
  inorderTreeWalk(T.root);
  cout << "\nPREORDER-TREE-WALK(T.root): ";
  preorderTreeWalk(T.root);
  cout << "\nPOSTORDER-TREE-WALK(T.root): ";
  postorderTreeWalk(T.root);
}

int main() {
  print(string("12.3-5"));

  cout << "Initialize a binary search tree T\n";
  BST T;
  T.root = new TreeNode(15);
  treeInsert(T, new TreeNode(6));
  treeInsert(T, new TreeNode(18));
  treeInsert(T, new TreeNode(3));
  treeInsert(T, new TreeNode(7));
  treeInsert(T, new TreeNode(17));
  treeInsert(T, new TreeNode(20));
  treeInsert(T, new TreeNode(2));
  treeInsert(T, new TreeNode(4));
  treeInsert(T, new TreeNode(13));
  treeInsert(T, new TreeNode(9));
  traversal(T);

  cout << "\n\nRemoving an item with key 15";
  treeDelete(T, T.root);
  traversal(T);

  cout << "\n\nRemoving an item with key 6";
  treeDelete(T, T.root->left);
  traversal(T);
}
