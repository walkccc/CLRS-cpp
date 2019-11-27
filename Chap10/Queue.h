#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue : private vector<T> {
 public:
  using vector<T>::vector;
  using vector<T>::operator[];
  using vector<T>::size;

  int head;
  int tail;
  void setHead();
  void setTail();
};

template <class T>
void Queue<T>::setHead() {
  for (int i = 0; i < this->size(); i++) {
    if ((*this)[i] != 0) {
      this->head = i;
      break;
    }
  }
}

template <class T>
void Queue<T>::setTail() {
  for (int i = this->size() - 1; i >= 0; i--) {
    if ((*this)[i - 1] != 0) {
      this->tail = i;
      break;
    }
  }
}

#endif