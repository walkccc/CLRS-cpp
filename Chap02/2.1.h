#ifndef ch2_1_h
#define ch2_1_h

#include "../print.h"

using std::vector;

// [Page 18]
//   INSERTION-SORT(A)
//   - Time: O(n^2)
//
// [Page 22]
//   NONINCREASING-INSERTION-SORT(A)
//   - Time: O(n^2)
//
//   LINEAR-SEARCH(A)
//   - Time: O(n)

namespace CLRS {
namespace CH2 {
template <typename T>
void insertionSort(vector<T>& A) {
  for (int j = 1; j < A.size(); j++) {
    int key = A[j];
    // Insert A[j] into the sorted sequence A[1..j - 1].
    int i = j - 1;
    while (i >= 0 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
    print(A);
  }
}

template <typename T>
void nonincreasingInsertionSort(vector<T>& A) {
  for (int j = 1; j < A.size(); j++) {
    int key = A[j];
    // Insert A[j] into the sorted sequence A[1..j - 1].
    int i = j - 1;
    while (i >= 0 && A[i] < key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
    print(A);
  }
}

template <typename T>
int linearSearch(vector<T>& A, int v) {
  for (int i = 0; i < A.size(); i++)
    if (A[i] == v)
      return i;
  return -1;
}
}  // namespace CH2
}  // namespace CLRS

#endif