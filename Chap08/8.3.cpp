#include "8.3.h"
#include "../print.h"

using namespace CLRS::CH8;

int main() {
  print(string("8.3 Radix sort"));

  cout << "Initialize an array of 3-digit numbers as Figure 8.3\n";
  vector<int> A = {329, 457, 657, 839, 436, 720, 355};
  print(A);

  cout << "\nPerform RADIX-SORT(A, 3)\n";
  radixSort(A, 3);
}