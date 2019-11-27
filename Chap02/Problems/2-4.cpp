#include "2-4.h"

using namespace CLRS::CH2;

int main() {
  print(string("Problem 2-4 Inversions"));

  cout << "Initialize an array A as 2-4 (a)\n";
  vector<int> A = {2, 3, 8, 6, 1};
  print(A);

  cout << "\nPerform COUNT-INVERSIONS(A, 0, 4)\n"
       << "The inversions of A is " << countInversions(A, 0, 4) << endl;
}