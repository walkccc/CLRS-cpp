#include "2.1.h"

using namespace CLRS::CH2;

int main() {
  print(string("Chapter 2.1 Insertion sort"));

  cout << "Initialize an array A as Figure 2.2\n";
  vector<int> A = {5, 2, 4, 6, 1, 3};
  print(A);

  cout << "\nPerform INSERTION-SORT(A)\n";
  insertionSort(A);

  cout << "\nPerform NONINCREASING-INSERTION-SORT(A)\n";
  nonincreasingInsertionSort(A);
}