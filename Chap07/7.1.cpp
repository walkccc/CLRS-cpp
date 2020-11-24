#include "7.1.h"

#include "../print.h"

using namespace CLRS::CH7;

int main() {
  print(string("Chapter 7.1 Description of quicksort"));

  cout << "Initialize an array A as Figure 7.1\n";
  vector<int> A = {2, 8, 7, 1, 3, 5, 6, 4};
  print(A);

  cout << "\nPerform PARTITION(A, 0, 7)\n";
  partition(A, 0, 7);
  print(A);

  cout << "\nPerform QUICKSORT(A, 0, 7)\n";
  quicksort(A, 0, 7);
  print(A);
}