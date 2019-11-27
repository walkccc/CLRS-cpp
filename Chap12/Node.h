#ifndef Node_h
#define Node_h

struct Node {
  int key;
  Node* left;
  Node* right;
  Node* p;
  Node(int x) : key(x), left(nullptr), right(nullptr), p(nullptr){};
};

#endif