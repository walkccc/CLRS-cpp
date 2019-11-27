#include "6.3.h"

using namespace CLRS::CH6;

int main() {
  print(string("Chapter 6.3 Building a heap"));

  cout << "Initialize a heap A as Figure 6.3\n";
  Heap<int> A = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  A.setHeapsize();
  print(A);

  cout << "\nPerform BUILD-MAX-HEAP(A)\n";
  buildMaxHeap(A);
}