#ifndef prob2_2_h
#define prob2_2_h

#include "../../print.h"

using std::vector;

// [Page 40]
//   BUBBLE-SORT(A)
//   - Time: O(n^2)

namespace CLRS {
namespace CH2 {
template <class T>
void bubbleSort(vector<T>& A) {
  for (int i = 0; i < A.size() - 1; i++)
    for (int j = A.size() - 1; j >= i + 1; j--)
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        print(A);
      }
}
}  // namespace CH2
}  // namespace CLRS

#endif