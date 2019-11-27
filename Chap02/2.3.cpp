#include "2.3.h"

using namespace CLRS::CH2;

int main() {
  print(string("Chapter 2.3 Designing algorithms"));

  cout << "Initialize an array A as Figure 2.3\n";
  vector<int> A(20);
  A[9] = 2;
  A[10] = 4;
  A[11] = 5;
  A[12] = 7;
  A[13] = 1;
  A[14] = 2;
  A[15] = 3;
  A[16] = 6;
  print(A);

  cout << "\nPerform MERGE(A, 9, 12, 16)\n";
  merge(A, 9, 12, 16);

  cout << "\nInitialize an array A as Figure 2.4\n";
  A = {5, 2, 4, 7, 1, 3, 2, 6};
  print(A);

  cout << "\nPerform MERGE-SORT(A, 0, 7)\n";
  mergeSort(A, 0, 7);
  print(A);

  cout << "\nPerform ITERATIVE-BINARY-SEARCH(A, 6, 0, 7)\n"
       << "The index of 6 is " << iterativeBinarySearch(A, 6, 0, 7) << endl;

  cout << "\nPerform RECURSIVE-BINARY-SEARCH(A, 6, 0, 7)\n"
       << "The index of 6 is " << recursiveBinarySearch(A, 6, 0, 7) << endl;
}