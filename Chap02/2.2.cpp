#include "2.2.h"

using namespace CLRS::CH2;

int main() {
  print(string("Chapter 2.2 Designing algorithms"));

  cout << "Initialize an array A as Figure 2.2\n";
  vector<int> A = {5, 2, 4, 6, 1, 3};
  print(A);

  cout << "\nPerform SELECTION-SORT(A)\n";
  selectionSort(A);
}