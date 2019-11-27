#include "12.3.h"
#include "12.1.h"

using namespace CLRS::CH12;

int main() {
  print(string("Chapter 12.3 Insertion and deletion"));

  cout << "Initialize a binary search tree T as Figure 12.3\n";
  BST T;
  T.root = new Node(12);
  recursiveTreeInsert(T.root, new Node(5));
  recursiveTreeInsert(T.root, new Node(18));
  recursiveTreeInsert(T.root, new Node(2));
  recursiveTreeInsert(T.root, new Node(9));
  recursiveTreeInsert(T.root, new Node(15));
  recursiveTreeInsert(T.root, new Node(19));
  recursiveTreeInsert(T.root, new Node(17));
  cout << "RECURSIVE-INORDER-TREE-WALK(T.root)\n";
  inorderTreeWalk(T.root);
  cout << "\n\n"
       << "      12" << endl
       << "     /   \\" << endl
       << "    5     18" << endl
       << "   / \\   /  \\" << endl
       << "  2   9 15  19" << endl
       << "         \\" << endl
       << "          17" << endl;

  cout << "\nInserting an item with key 13\n";
  treeInsert(T, new Node(13));
  cout << "RECURSIVE-INORDER-TREE-WALK(T.root)\n";
  inorderTreeWalk(T.root);
  cout << "\n\n"
       << "      12" << endl
       << "     /   \\" << endl
       << "    5     18" << endl
       << "   / \\   /  \\" << endl
       << "  2   9 15  19" << endl
       << "       / \\" << endl
       << "     13   17" << endl;

  cout << "\nRemoving an item with key 18\n";
  treeDelete(T, T.root->right);
  cout << "RECURSIVE-INORDER-TREE-WALK(T.root)\n";
  inorderTreeWalk(T.root);
  cout << "\n\n"
       << "      12" << endl
       << "     /   \\" << endl
       << "    5     19" << endl
       << "   / \\   /" << endl
       << "  2   9 15" << endl
       << "       / \\" << endl
       << "     13   17" << endl;

  cout << "\nRemoving an item with key 15\n";
  treeDelete(T, T.root->right->left);
  cout << "RECURSIVE-INORDER-TREE-WALK(T.root)\n";
  inorderTreeWalk(T.root);
  cout << "\n\n"
       << "      12" << endl
       << "     /   \\" << endl
       << "    5     19" << endl
       << "   / \\   /" << endl
       << "  2   9 13" << endl
       << "         \\" << endl
       << "          17" << endl;
}
