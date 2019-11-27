#ifndef prob7_2_h
#define prob7_2_h

#include <vector>

using std::swap;
using std::vector;

// [Page 186]
//   PARTITION'(A, p, r)
//   - Time: O(n)
//
//   QUICKSORT'(A, p, r)
//   - Average time: O(n lg n)
//   - Worst time: O(n^2)

namespace CLRS {
namespace CH7 {
template <typename T>
vector<int> partition_(vector<T>& A, int p, int r) {
  T x = A[p];
  int low = p;
  int high = p;
  for (int j = p + 1; j <= r; j++) {
    if (A[j] < x) {
      int y = A[j];
      A[j] = A[high + 1];
      A[high + 1] = A[low];
      A[low] = y;
      low++;
      high++;
    } else if (A[j] == x) {
      swap(A[high + 1], A[j]);
      high++;
    }
  }
  return {low, high};
}

template <typename T>
void quicksort_(vector<T>& A, int p, int r) {
  if (p < r) {
    vector<int> bound = partition_(A, p, r);
    quicksort_(A, p, bound[0] - 1);
    quicksort_(A, bound[1] + 1, r);
  }
}
}  // namespace CH7
}  // namespace CLRS

#endif