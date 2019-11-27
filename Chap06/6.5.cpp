#include "6.5.h"

using namespace CLRS::CH6;

int main() {
  print(string("Chapter 6.5 Priority queues"));

  cout << "Initialize a heap A as Figure 6.5\n";
  Heap<int> A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  A.setHeapsize();
  print(A);
  cout << "\nPerform HEAP-INCREASE-KEY(A, 8, 15)\n";
  heapIncreaseKey(A, 8, 15);
  print(A);

  cout << "\nInitialize a heap A as Exercise 6.5-1\n";
  A = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
  A.setHeapsize();
  print(A);
  cout << "\nPerform HEAP-EXTRACT-MAX(A)\n";
  heapExtractMax(A);
  print(A);

  cout << "\nInitialize a heap A as Exercise 6.5-2\n";
  A = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
  A.setHeapsize();
  print(A);
  cout << "\nPerform MAX-HEAP-INSERT(A, 10)\n";
  maxHeapInsert(A, 10);
  print(A);
}