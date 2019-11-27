#include "4.1.h"
#include "../print.h"

using namespace CLRS::CH4;

int main() {
  print(string("Chapter 4.1 The maximum-subarray problem"));

  cout << "Initialize an array A as Figure 4.3\n";
  vector<int> A = {13, -3, -25, 20, -3,  -16, -23, 18,
                   20, -7, 12,  -5, -22, 15,  -4,  7};
  print(A);

  Ans ans = findMaximumSubarray(A, 0, 15);
  cout << "\nPerform FIND-MAXIMUM-SUBARRAY(A, 0, 15)\n"
       << "The (low, high, sum) of the maximum subarray of A are (" << ans.low
       << ", " << ans.high << ", " << ans.sum << ")\n";

  ans = bruteForceFindMaximumSubarray(A);
  cout << "\nPerform FIND-MAXIMUM-SUBARRAY-BRUTE-FORCE(A)\n"
       << "The (low, high, sum) of the maximum subarray of A are (" << ans.low
       << ", " << ans.high << ", " << ans.sum << ")\n";

  ans = iterativeFindMaximumSubarray(A);
  cout << "\nPerform FIND-MAXIMUM-SUBARRAY-LINEAR(A)\n"
       << "The (low, high, sum) of the maximum subarray of A are (" << ans.low
       << ", " << ans.high << ", " << ans.sum << ")\n";
}