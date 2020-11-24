#ifndef ch2_2_h
#define ch2_2_h

#include "../print.h"

using std::vector;

// [Page 29][2.2-2]
//   SELECTION-SORT(A)
//   - Time: O(n^2)

namespace CLRS {
namespace CH2 {
template <typename T>
void selectionSort(vector<T>& A) {
  int n = A.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
      if (A[j] < A[minIndex])
        minIndex = j;
    swap(A[i], A[minIndex]);
    print(A);
  }
}
}  // namespace CH2
}  // namespace CLRS

#endif