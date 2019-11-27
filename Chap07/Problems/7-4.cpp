#include "7-4.h"
#include "../../print.h"

using namespace CLRS::CH7;

int main() {
  print(string("Problem 7-4 Stack depth for quicksort"));

  cout << "Initialize an array A as 7-1 (a)\n";
  vector<int> A = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
  print(A);

  cout << "\nPerform TAIL-RECURSIVE-QUICKSORT(A, 0, 11)\n";
  tailRecursiveQuicksort(A, 0, 11);

  A = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
  cout << "\nPerform MODIFIED-TAIL-RECURSIVE-QUICKSORT(A, 0, 11)\n";
  modifiedTailRecursiveQuicksort(A, 0, 11);
  print(A);
}