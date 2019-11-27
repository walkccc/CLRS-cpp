#ifndef ch8_3_h
#define ch8_3_h

#include <cmath>
#include <vector>
#include "../print.h"

using std::pow;
using std::vector;

// [Page 198]
//   COUNTING-SORT(A, B, digits, k)
//   - Time: O(n)
//
//   RADIX-SORT(A, d)
//   - Time: O(n + k)

namespace CLRS {
namespace CH8 {
void countingSort(vector<int>& A, vector<int>& B, vector<int>& digits, int k) {
  vector<int> C(k + 1, 0);
  for (int j = 0; j < A.size(); j++) {
    C[digits[j]]++;
  }
  for (int i = 1; i <= k; i++) {
    C[i] += C[i - 1];
  }
  for (int j = A.size() - 1; j >= 0; j--) {
    B[C[digits[j]] - 1] = A[j];
    C[digits[j]]--;
  }
}

void radixSort(vector<int>& A, int d, int k = 9) {
  for (int i = 1; i <= d; i++) {
    // use a stable sort to sort array A on digit i
    vector<int> B(A.size(), 0);
    vector<int> digits(A.size(), 0);
    for (int j = 0; j < A.size(); j++) {
      digits[j] = A[j] / (int)(pow(10, i - 1)) % 10;
    }
    countingSort(A, B, digits, 9);
    A = B;
    print(A);
  }
}
}  // namespace CH8
}  // namespace CLRS

#endif