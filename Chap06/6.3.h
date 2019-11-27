#ifndef ch6_3_h
#define ch6_3_h

#include "../print.h"
#include "6.2.h"
#include "Heap.h"

// [Page 157]
//   BUILD-MAX-HEAP(A)
//   - Time: O(n)

namespace CLRS {
namespace CH6 {
template <typename T>
void buildMaxHeap(Heap<T>& A) {
  for (int i = A.heapsize / 2; i >= 0; i--) {
    maxHeapify(A, i);
    print(A);
  }
}
}  // namespace CH6
}  // namespace CLRS

#endif