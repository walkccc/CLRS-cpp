#ifndef ch4_1_h
#define ch4_1_h

#include <vector>

using std::vector;

// [Page 71]
//   FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
//   - Time: O(n)
//
// [Page 72]
//   FIND-MAXIMUM-SUBARRAY(A, low, high)
//   - Time: O(n lg n)
//
// [Page 74][4.1-2]
//   BRUTE-FORCE-FIND-MAXIMUM-SUBARRAY(A)
//   - Time: O(n^2)
//
// [Page 75][4.1-5]
//   ITERATIVE-FIND-MAXIMUM-SUBARRAY(A)
//   - Time: O(n)

namespace CLRS {
namespace CH4 {
template <typename T>
class Ans {
 public:
  int low;
  int high;
  T sum;
};

template <typename T>
Ans<T> findMaxCrossingSubarray(vector<T>& A, int low, int mid, int high) {
  int maxLeft = 0;
  T leftSum = INT_MIN;
  T sum = 0;
  for (int i = mid; i >= low; i--) {
    sum = sum + A[i];
    if (sum > leftSum) {
      leftSum = sum;
      maxLeft = i;
    }
  }
  int maxRight = 0;
  T rightSum = INT_MIN;
  sum = 0;
  for (int j = mid + 1; j <= high; j++) {
    sum = sum + A[j];
    if (sum > rightSum) {
      rightSum = sum;
      maxRight = j;
    }
  }
  return {maxLeft, maxRight, leftSum + rightSum};
}

template <typename T>
Ans<T> findMaximumSubarray(vector<T>& A, int low, int high) {
  if (high == low) {
    return {low, high, A[low]};
  } else {
    int mid = (low + high) / 2;
    Ans<T> left = findMaximumSubarray(A, low, mid);
    Ans<T> right = findMaximumSubarray(A, mid + 1, high);
    Ans<T> cross = findMaxCrossingSubarray(A, low, mid, high);
    if (left.sum >= right.sum && left.sum >= cross.sum)
      return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
      return right;
    else
      return cross;
  }
}

template <typename T>
Ans<T> bruteForceFindMaximumSubarray(vector<T>& A) {
  int n = A.size();
  int low = 0;
  int high = 0;
  T maxSum = INT_MIN;
  for (int i = 0; i < n; i++) {
    T sum = 0;
    for (int j = i; j < n; j++) {
      sum = sum + A[j];
      if (sum > maxSum) {
        maxSum = sum;
        low = i;
        high = j;
      }
    }
  }
  return {low, high, maxSum};
}

template <typename T>
Ans<T> iterativeFindMaximumSubarray(vector<T>& A) {
  int n = A.size();
  int low = 0;
  int high = 0;
  T maxSum = INT_MIN;
  T sum = INT_MIN;
  for (int j = 0; j < n; j++) {
    int currentLow;
    int currentHigh = j;
    if (sum > 0) {
      sum = sum + A[j];
    } else {
      currentLow = j;
      sum = A[j];
    }
    if (sum > maxSum) {
      maxSum = sum;
      low = currentLow;
      high = currentHigh;
    }
  }
  return {low, high, maxSum};
}
}  // namespace CH4
}  // namespace CLRS

#endif