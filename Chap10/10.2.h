#ifndef ch10_2_h
#define ch10_2_h

#include "List.h"
#include "../print.h"

// [Page 237]
//   LIST-SEARCH(L, k)
//   - Time: O(n)
//
// [Page 238]
//   LIST-INSERT(L, x)
//   - Time: O(1)
//
//   LIST-DELETE(L, x)
//   - Time: O(1)
//
//   LIST-DELETE'(L, x)
//   - Time: O(1)
//
// [Page 239]
//   LIST-SEARCH'(L, x)
//   - Time: O(1)
//
// [Page 240]
//   LIST-INSERT'(L, x)
//   - Time: O(1)

namespace CLRS {
namespace CH10 {
template <typename T>
Node<T>* listSearch(List<T>& L, T k) {
  Node<T>* x = L.head;
  while (x != nullptr and x->key != k) {
    x = x->next;
  }
  return x;
}

template <typename T>
void listInsert(List<T>& L, Node<T>* x) {
  x->next = L.head;
  if (L.head != nullptr) {
    L.head->prev = x;
  }
  L.head = x;
  x->prev = nullptr;
}

template <typename T>
void listDelete(List<T>& L, Node<T>* x) {
  if (x->prev != nullptr)
    x->prev->next = x->next;
  else
    L.head = x->next;
  if (x->next != nullptr) {
    x->next->prev = x->prev;
  }
}

template <typename T>
Node<T>* listSearch_(List_<T>& L, T k) {
  Node<T>* x = L.nil->next;
  while (x != L.nil and x->key != k) {
    x = x->next;
  }
  return x;
}

template <typename T>
void listInsert_(List_<T>& L, Node<T>* x) {
  x->next = L.nil->next;
  L.nil->next->prev = x;
  L.nil->next = x;
  x->prev = L.nil;
}

template <typename T>
void listDelete_(List_<T>& L, Node<T>* x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
}
}  // namespace CH10
}  // namespace CLRS

#endif