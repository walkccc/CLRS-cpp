#include "4.2.h"

#include "../print.h"

using namespace CLRS::CH4;

int main() {
  print(string("Chapter 4.2 Strassen's algorithm for matrix multiplication"));

  cout << "Initialize two matrice as Exercise 4.2-1\n";
  Matrix<int> A({{1, 3}, {7, 5}});
  Matrix<int> B({{6, 8}, {4, 2}});
  cout << "A = \n" << A << endl;
  cout << "B = \n" << B << endl;

  cout << "C = SQUARE-MATRIX-MULTIPLY(A, B) =\n";
  Matrix<int> C = squareMatrixMultiply<int>(A, B);
  cout << C << endl;

  cout << "C = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B) =\n";
  C = squareMatrixMultiplyRecursive<int>(A, B);
  cout << C << endl;

  cout << "C = STRASSEN(A, B) =\n";
  C = strassen<int>(A, B);
  cout << C << endl;
}