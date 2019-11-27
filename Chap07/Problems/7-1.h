#ifndef prob7_1_h
#define prob7_1_h

#include <vector>

using std::swap;
using std::vector;

// [Page 185]
//   HOARE-PARTITION(A, p, r)
//   - Time: O(n)
//
//   HOARE-QUICKSORT(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)

namespace CLRS {
namespace CH7 {
template <typename T>
int hoarePartition(vector<T>& A, int p, int r) {
  T x = A[p];
  int i = p - 1;
  int j = r + 1;
  while (true) {
    do {
      j = j - 1;
    } while (A[j] > x);
    do {
      i = i + 1;
    } while (A[i] < x);
    if (i < j)
      swap(A[i], A[j]);
    else
      return j;
  }
}

template <typename T>
void hoareQuicksort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = hoarePartition(A, p, r);
    hoareQuicksort(A, p, q - 1);
    hoareQuicksort(A, q + 1, r);
  }
}
}  // namespace CH7
}  // namespace CLRS

#endif