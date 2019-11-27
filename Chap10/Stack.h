#ifndef Stack_h
#define Stack_h

#include <vector>

using namespace std;

template <class T>
class Stack : private vector<T> {
 public:
  using vector<T>::vector;
  using vector<T>::operator[];
  using vector<T>::size;
  using vector<T>::resize;

  int top;
  void setTop();
};

template <class T>
void Stack<T>::setTop() {
  this->top = this->size() - 1;
  this->resize(7);
}

#endif