#ifndef ch6_4_h
#define ch6_4_h

#include "../print.h"
#include "6.2.h"
#include "6.3.h"
#include "Heap.h"

// [Page 160]
//   HEAPSORT(A)
//   - Time: O(n lg n)

namespace CLRS {
namespace CH6 {
template <typename T>
void heapsort(Heap<T>& A) {
  buildMaxHeap(A);
  for (int i = A.heapsize - 1; i >= 1; i--) {
    swap(A[0], A[i]);
    A.heapsize--;
    maxHeapify(A, 0);
    print(A);
  }
}
}  // namespace CH6
}  // namespace CLRS

#endif