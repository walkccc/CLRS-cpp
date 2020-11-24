#ifndef prob2_4_h
#define prob2_4_h

#include "../../print.h"

using std::vector;

// [Page 41]
//   MERGE-INVERSIONS(A, p, q, r)
//   - Time: O(n)
//
//   COUNT-INVERSIONS(A)
//   - Time: O(n lg n)

namespace CLRS {
namespace CH2 {
template <typename T>
int mergeInversions(vector<T>& A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  vector<int> L(n1 + 1), R(n2 + 1);
  for (int i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = A[q + j + 1];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0;
  int j = 0;
  int inversions = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      inversions = inversions + n1 - i;
      A[k] = R[j];
      j = j + 1;
    }
  }
  return inversions;
}

template <typename T>
int countInversions(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    int left = countInversions(A, p, q);
    int right = countInversions(A, q + 1, r);
    return mergeInversions(A, p, q, r) + left + right;
  }
  return 0;
}
}  // namespace CH2
}  // namespace CLRS

#endif
