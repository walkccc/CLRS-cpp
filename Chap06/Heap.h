#ifndef Heap_h
#define Heap_h

#include <vector>

using std::vector;

template <typename T>
class Heap : private vector<T> {
 public:
  using vector<T>::vector;
  using vector<T>::operator[];
  using vector<T>::size;

  int heapsize;
  void setHeapsize();
};

template <typename T>
void Heap<T>::setHeapsize() {
  heapsize = this->size();
}

#endif