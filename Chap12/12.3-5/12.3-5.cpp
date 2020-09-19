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

  TreeNode* six = T.root->left;
  TreeNode* three = six->left;
  TreeNode* seven = six->right;
  TreeNode* four = three->right;
  TreeNode* thirteen = seven->right;
  TreeNode* nine = thirteen->left;
  TreeNode* eighteen = T.root->right;
  TreeNode* seventeen = eighteen->left;
  TreeNode* twenty = eighteen->right;

  cout << "\n\nPrint predecessors of each node\n";
  cout << "3's pred = " << treePredecessor(T, three)->key << endl;
  cout << "4's pred = " << treePredecessor(T, four)->key << endl;
  cout << "6's pred = " << treePredecessor(T, six)->key << endl;
  cout << "7's pred = " << treePredecessor(T, seven)->key << endl;
  cout << "9's pred = " << treePredecessor(T, nine)->key << endl;
  cout << "13's pred = " << treePredecessor(T, thirteen)->key << endl;
  cout << "15 (root)'s pred = " << treePredecessor(T, T.root)->key << endl;
  cout << "17's pred = " << treePredecessor(T, seventeen)->key << endl;
  cout << "18's pred = " << treePredecessor(T, eighteen)->key << endl;
  cout << "20's pred = " << treePredecessor(T, twenty)->key;

  cout << "\n\nRemoving an item with key 15";
  treeDelete(T, T.root);
  traversal(T);

  cout << "\n\nRemoving an item with key 6";
  treeDelete(T, T.root->left);
  traversal(T);
}
