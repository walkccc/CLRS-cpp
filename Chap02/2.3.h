#ifndef ch2_3_h
#define ch2_3_h

#include "../print.h"

using std::vector;

// [Page 32]
//   MERGE(A, p, q, r)
//   - Time: O(n)
//
// [Page 32]
//   MERGE-SORT(A, p, r)
//   - Time: O(n lg n)
//
// [Page 39]
//   MERGE-WITHOUT-SENTINELS(A, p, q, r)
//   - Time: O(n)
//
// [Page 39][2.3-5]
//   ITERATIVE-BINARY-SEARCH(A, v, low, high)
//   - Time: O(lg n)
//
//   RECURSIVE-BINARY-SEARCH(A, v, low, high)
//   - Time: O(lg n)

namespace CLRS {
namespace CH2 {
template <typename T>
void merge(vector<T>& A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  vector<T> L(n1 + 1), R(n2 + 1);
  // The indices here are different from the book because the index of C++
  // starts from 0 instead of 1.
  for (int i = 0; i < n1; i++) L[i] = A[p + i];
  for (int j = 0; j < n2; j++) R[j] = A[q + j + 1];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0;
  int j = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
    print(A);
  }
}

template <typename T>
void mergeWithoutSentinels(vector<T>& A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  vector<T> L(n1 + 1), R(n2 + 1);
  for (int i = 0; i < n1; i++) L[i] = A[p + i];
  for (int j = 0; j < n2; j++) R[j] = A[q + j + 1];
  int i = 0;
  int j = 0;
  for (int k = p; k <= r; k++) {
    if (i >= n1) {
      A[k] = R[j];
      j = j + 1;
    } else if (j >= n2) {
      A[k] = L[i];
      i = i + 1;
    } else if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
    print(A);
  }
}

template <typename T>
void mergeSort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    mergeWithoutSentinels(A, p, q, r);
  }
}

int iterativeBinarySearch(vector<int>& A, int v, int low, int high) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (v == A[mid])
      return mid;
    else if (v > A[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int recursiveBinarySearch(vector<int>& A, int v, int low, int high) {
  if (low > high) return -1;
  int mid = (low + high) / 2;
  if (v == A[mid])
    return mid;
  else if (v > A[mid])
    return recursiveBinarySearch(A, v, mid + 1, high);
  else
    return recursiveBinarySearch(A, v, low, mid - 1);
}
}  // namespace CH2
}  // namespace CLRS

#endif