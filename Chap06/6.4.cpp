#include "6.4.h"

using namespace CLRS::CH6;

int main() {
  print(string("Chapter 6.4 The heapsort algorithm"));

  cout << "Initialize a heap A as Figure 6.4\n";
  Heap<int> A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  A.setHeapsize();
  print(A);

  cout << "\nPerform HEAPSORT(A)\n";
  heapsort(A);
}