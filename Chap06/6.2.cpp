#include "6.2.h"
#include "../print.h"

using namespace CLRS::CH6;

int main() {
  print(string("Chapter 6.2 Maintaining the heap property"));

  cout << "Initialize a heap A as Figure 6.2\n";
  Heap<int> A = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  A.setHeapsize();
  print(A);

  cout << "\nPerform MAX-HEAPIFY(A, 1)\n";
  maxHeapify(A, 1);
  print(A);

  A = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  A.setHeapsize();
  cout << "\nPerform ITERATIVE-MAX-HEAPIFY(A, 1)\n";
  iterativeMaxHeapify(A, 1);
  print(A);
}