#ifndef List_h
#define List_h

template <typename T>
class ListNode {
 public:
  ListNode(const T);

  T key;
  ListNode* prev;
  ListNode* next;
};

template <typename T>
ListNode<T>::ListNode(const T key) {
  this->key = key;
  prev = nullptr;
  next = nullptr;
}

template <typename T>
class List {
 public:
  ListNode<T>* head;
};

template <typename T>
class List_ {
 public:
  List_();

  ListNode<T>* nil = new ListNode<T>(0);
};

template <typename T>
List_<T>::List_() {
  nil->next = nil;
  nil->prev = nil;
}

#endif