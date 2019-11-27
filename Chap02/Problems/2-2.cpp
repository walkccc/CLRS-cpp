#include "2-2.h"

using namespace CLRS::CH2;

int main() {
  print(string("Problem 2-2 Correctness of bubblesort"));

  cout << "Initialize an array A as Figure 2.2\n";
  vector<int> A = {5, 2, 4, 6, 1, 3};
  print(A);

  cout << "\nPerform BUBBLE-SORT(A)\n";
  bubbleSort(A);
}