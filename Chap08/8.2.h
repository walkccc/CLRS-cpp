#ifndef ch8_2_h
#define ch8_2_h

#include <vector>

using std::vector;

// [Page 195]
//   COUNTING-SORT(A, B, k)
//   - Time: O(n)

namespace CLRS {
namespace CH8 {
void countingSort(vector<int>& A, vector<int>& B, int k) {
  vector<int> C(k + 1, 0);
  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }
  for (int j = 0; j < A.size(); j++) {
    C[A[j]]++;
  }
  // C[i] now contains the number of elements equal to i.
  for (int i = 1; i <= k; i++) {
    C[i] += C[i - 1];
  }
  // C[i] now contains the number of elements less than or equal to i.
  for (int j = A.size() - 1; j >= 0; j--) {
    B[C[A[j]] - 1] = A[j];
    C[A[j]]--;
  }
}
}  // namespace CH8
}  // namespace CLRS

#endif