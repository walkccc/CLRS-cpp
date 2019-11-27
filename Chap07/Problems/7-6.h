#ifndef prob7_6_h
#define prob7_6_h

#include <vector>
#include "../../Chap05/5.1.h"
#include "../7.1.h"

using std::swap;
using std::vector;

typedef struct {
  int a;
  int b;
} Interval;

// [Page 189]
//   FIND-INTERSECTION(A, p, r)
//   - Time: O(n)
//
//   PARTITION-RIGHT(A, a, p, r)
//   - Time: O(n)
//
//   PARTITION-LEFT(A, b, p, t)
//   - Time: O(n)
//
//   FUZZY-SORT(A, p, r)
//   - Time: O(n log n)
//   - Best time: O(n) (when all of the intervals overlap)

namespace CLRS {
namespace CH7 {
Interval findIntersection(vector<Interval>& A, int p, int r) {
  int rand = CH5::random(p, r);
  swap(A[rand], A[r]);
  int a = A[r].a;
  int b = A[r].b;
  for (int i = p; i <= r - 1; i++) {
    if (A[i].a <= b && A[i].b >= a) {
      if (A[i].a > a) a = A[i].a;
      if (A[i].b < b) b = A[i].b;
    }
  }
  return {a, b};
}

int partitionRight(vector<Interval>& A, int a, int p, int r) {
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j].a <= a) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

int partitionLeft(vector<Interval>& A, int b, int p, int t) {
  int i = p - 1;
  for (int j = p; j <= t - 1; j++) {
    if (A[j].b < b) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[t]);
  return i + 1;
}

void fuzzySort(vector<Interval>& A, int p, int r) {
  if (p < r) {
    Interval interval = findIntersection(A, p, r);
    int t = partitionRight(A, interval.a, p, r);
    int q = partitionLeft(A, interval.b, p, t);
    fuzzySort(A, p, q - 1);
    fuzzySort(A, t + 1, r);
  }
}
}  // namespace CH7
}  // namespace CLRS

#endif