#ifndef prob7_4_h
#define prob7_4_h

#include <vector>
#include "../7.1.h"

using std::swap;
using std::vector;

// [Page 188]
//   TAIL-RECURSIVE-QUICKSORT(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)
//
//   MODIFIED-TAIL-RECURSIVE-QUICKSORT(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)

namespace CLRS {
namespace CH7 {
template <typename T>
void tailRecursiveQuicksort(vector<T>& A, int p, int r) {
  while (p < r) {
    int q = partition(A, p, r);
    tailRecursiveQuicksort(A, p, q - 1);
    p = q + 1;
  }
}

template <typename T>
void modifiedTailRecursiveQuicksort(vector<T>& A, int p, int r) {
  while (p < r) {
    int q = partition(A, p, r);
    if (q < (p + r) / 2) {
      modifiedTailRecursiveQuicksort(A, p, q - 1);
      p = q + 1;
    } else {
      modifiedTailRecursiveQuicksort(A, q + 1, r);
      r = q - 1;
    }
  }
}
}  // namespace CH7
}  // namespace CLRS

#endif