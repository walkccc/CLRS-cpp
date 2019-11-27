#include "7-6.h"

using namespace CLRS::CH7;

void printIntervals(vector<Interval>& A) {
  for (int i = 0; i < A.size(); i++) {
    cout << "(" << A[i].a << ", " << A[i].b << ")" << endl;
  }
}

int main() {
  print(string("Problem 7-6 Fuzzy sorting of intervals"));

  cout << "Initialize an array of interval A\n";
  vector<Interval> A = {{2, 3}, {0, 2}, {6, 8}, {7, 8},  {2, 4},
                        {0, 1}, {4, 6}, {1, 2}, {9, 10}, {5, 6}};
  printIntervals(A);

  cout << "\nPerform FUZZY-SORT(A, 0, 9)\n";
  fuzzySort(A, 0, 14);
  printIntervals(A);
}