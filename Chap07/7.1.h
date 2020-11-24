#ifndef ch7_1_h
#define ch7_1_h

#include <vector>

#include "../print.h"

using std::swap;
using std::vector;

// [Page 171]
//   QUICKSORT(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)
//
//   PARTITION(A, p, r)
//   - Time: O(n)

namespace CLRS {
namespace CH7 {
template <typename T>
int partition(vector<T>& A, int p, int r);

template <typename T>
void quicksort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

template <typename T>
int partition(vector<T>& A, int p, int r) {
  T x = A[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j] <= x) {
      i = i + 1;
      swap(A[i], A[j]);
    }
    print(A);
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}
}  // namespace CH7
}  // namespace CLRS

#endif