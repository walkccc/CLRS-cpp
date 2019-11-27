#ifndef ch7_3_h
#define ch7_3_h

#include "../Chap05/5.1.h"
#include "../print.h"
#include "7.1.h"

// [Page 179]
//   RANDOMIZED-PARTITION(A, p, r)
//   - Time: O(n)
//
//   RANDOMIZED-QUICKSORT(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)

namespace CLRS {
namespace CH7 {
template <typename T>
int randomizedPartition(vector<T>& A, int p, int r) {
  int i = CH5::random(p, r);
  swap(A[r], A[i]);
  return partition(A, p, r);
}

template <typename T>
void randomizedQuicksort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = randomizedPartition(A, p, r);
    randomizedQuicksort(A, p, q - 1);
    randomizedQuicksort(A, q + 1, r);
  }
}
}  // namespace CH7
}  // namespace CLRS

#endif