#include "10.2.h"
#include "../print.h"
#include "List.h"

using namespace CLRS::CH10;

int main() {
  print(string("Chapter 10.2 Linked lists"));

  cout << "Initialize a doubly linked list L as Figure 10.3 (a)\n";
  List<int> L;
  Node<int>* nodeToBeDeleted = new Node<int>(4);
  listInsert(L, new Node<int>(1));
  listInsert(L, nodeToBeDeleted);
  listInsert(L, new Node<int>(16));
  listInsert(L, new Node<int>(9));
  print(L);

  cout << "\nPerform LIST-INSERT(L, 25)\n";
  listInsert(L, new Node<int>(25));
  print(L);

  cout << "\nPerform LIST-DELETE(L, 4)\n";
  listDelete(L, nodeToBeDeleted);
  print(L);

  cout << "\nPerform LIST-SEARCH(L, 9)\n";
  Node<int>* searchedNode = listSearch(L, 9);
  cout << "The searched node is " << searchedNode->key << endl;

  cout << "\nInitialize a doubly linked list L as Figure 10.4 (b)\n";
  List_<int> L2;
  nodeToBeDeleted = new Node<int>(1);
  listInsert_(L2, nodeToBeDeleted);
  listInsert_(L2, new Node<int>(4));
  listInsert_(L2, new Node<int>(16));
  listInsert_(L2, new Node<int>(9));
  print(L2);

  cout << "\nPerform LIST-INSERT'(L, 25)\n";
  listInsert_(L2, new Node<int>(25));
  print(L2);

  cout << "\nPerform LIST-DELETE'(L, 1)\n";
  listDelete_(L2, nodeToBeDeleted);
  print(L2);

  cout << "\nPerform LIST-SEARCH'(L, 25)\n";
  searchedNode = listSearch_(L2, 25);
  cout << "The searched node is " << searchedNode->key << endl;
}
