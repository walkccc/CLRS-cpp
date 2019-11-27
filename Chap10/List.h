#ifndef List_h
#define List_h

template <typename T>
class Node {
 public:
  Node(const T);

  T key;
  Node* prev;
  Node* next;
};

template <typename T>
Node<T>::Node(const T key) {
  this->key = key;
  prev = nullptr;
  next = nullptr;
}

template <typename T>
class List {
 public:
  Node<T>* head;
};

template <typename T>
class List_ {
 public:
  List_();

  Node<T>* nil = new Node<T>(0);
};

template <typename T>
List_<T>::List_() {
  nil->next = nil;
  nil->prev = nil;
}

#endif