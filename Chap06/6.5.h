#ifndef ch6_5_h
#define ch6_5_h

#include "../print.h"
#include "6.2.h"
#include "6.3.h"
#include "Heap.h"

// [Page 163]
//   HEAP-MAXIMUM(A)
//   - Time: O(1)
//
//   HEAP-EXTRACT-MAX(A)
//   - Time: O(lg n)
//
// [Page 164]
//   HEAP-INCREASE0KEY(A, i, key)
//   - Time: O(lg n)
//
//   MAX-HEAP-INSERT(A, key)
//   - Time: O(lg n)

namespace CLRS {
namespace CH6 {
template <typename T>
int heapMaximum(Heap<T>& A) {
  return A[0];
}

template <typename T>
T heapExtractMax(Heap<T>& A) {
  if (A.heapsize < 1) throw("heap underflow");
  T max = A[0];
  A[0] = A[A.heapsize - 1];
  A.heapsize--;
  maxHeapify(A, 0);
  return max;
}

template <typename T>
void heapIncreaseKey(Heap<T>& A, int i, T key) {
  if (key < A[i]) throw("new key is smaller than current key");
  A[i] = key;
  while (i > 0 && A[parent(i)] < A[i]) {
    swap(A[i], A[parent(i)]);
    i = parent(i);
  }
}

template <typename T>
void maxHeapInsert(Heap<T>& A, T key) {
  A.heapsize++;
  A[A.heapsize - 1] = INT_MIN;
  heapIncreaseKey(A, A.heapsize - 1, key);
}
}  // namespace CH6
}  // namespace CLRS

#endif