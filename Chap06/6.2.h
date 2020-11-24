#ifndef ch6_2_h
#define ch6_2_h

#include "6.1.h"
#include "Heap.h"

using std::swap;

// [Page 154]
//   MAX-HEAPIFY(A, i)
//   - Time: O(lg n)
//
// [Page 156]
//   MIN-HEAPIFY(A, i)
//   - Time: O(lg n)
//
//   ITERATIVE-MAX-HEAPIFY(A, i)
//   - Time: O(lg n)

namespace CLRS {
namespace CH6 {
template <typename T>
void maxHeapify(Heap<T>& A, int i) {
  int l = left(i);
  int r = right(i);
  int largest;
  if (l <= A.heapsize - 1 && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if (r <= A.heapsize - 1 && A[r] > A[largest])
    largest = r;
  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(A, largest);
  }
}

template <typename T>
void minHeapify(Heap<T>& A, int i) {
  int l = left(i);
  int r = right(i);
  int smallest;
  if (l <= A.heapsize - 1 && A[l] < A[i])
    smallest = l;
  else
    smallest = i;
  if (r <= A.heapsize - 1 && A[r] < A[smallest])
    smallest = r;
  if (smallest != i) {
    swap(A[i], A[smallest]);
    minHeapify(A, smallest);
  }
}

template <typename T>
void iterativeMaxHeapify(Heap<T>& A, int i) {
  while (true) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l <= A.heapsize - 1 && A[l] > A[i])
      largest = l;
    else
      largest = i;
    if (r <= A.heapsize - 1 && A[r] > A[largest])
      largest = r;
    if (largest == i)
      return;
    swap(A[i], A[largest]);
    i = largest;
  }
}
}  // namespace CH6
}  // namespace CLRS

#endif