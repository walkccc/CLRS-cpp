#ifndef ch4_2_h
#define ch4_2_h

#include <vector>
#include "Matrix.cpp"

using std::vector;

// [Page 75]
//   SQUARE-MATRIX-MULTIPLY(A, B)
//   - Time: O(n^3)
//
// [Page 77]
//   SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B)
//   - Time: O(n^3)
//
// [Page 82][4.2-2]
//   STRASSEN(A, B)
//   - Time: O(n^(lg 7))

namespace CLRS {
namespace CH4 {
template <typename T>
Matrix<T> squareMatrixMultiply(Matrix<T> A, Matrix<T> B) {
  return A * B;
}

template <typename T>
Matrix<T> squareMatrixMultiplyRecursive(Matrix<T> A, Matrix<T> B) {
  int m = A.getRows();
  int n = A.getCols();

  Matrix<T> C(m, n);

  if (n == 1) {
    C.getP()[0][0] = A.getP()[0][0] * B.getP()[0][0];
  } else {
    Matrix<T> C11 = squareMatrixMultiplyRecursive(A.get11(), B.get11()) +
                    squareMatrixMultiplyRecursive(A.get12(), B.get21());
    Matrix<T> C12 = squareMatrixMultiplyRecursive(A.get11(), B.get12()) +
                    squareMatrixMultiplyRecursive(A.get12(), B.get22());
    Matrix<T> C21 = squareMatrixMultiplyRecursive(A.get21(), B.get11()) +
                    squareMatrixMultiplyRecursive(A.get22(), B.get21());
    Matrix<T> C22 = squareMatrixMultiplyRecursive(A.get21(), B.get12()) +
                    squareMatrixMultiplyRecursive(A.get22(), B.get22());
    C = combine(C11, C12, C21, C22);
  }

  return C;
}

template <typename T>
Matrix<T> strassen(Matrix<T> A, Matrix<T> B) {
  int m = A.getRows();
  int n = A.getCols();

  if (n == 1) return Matrix<T>({{A.getP()[0][0] * B.getP()[0][0]}});

  Matrix<T> C(m, n);
  Matrix<T> A11 = A.get11();
  Matrix<T> A12 = A.get12();
  Matrix<T> A21 = A.get21();
  Matrix<T> A22 = A.get22();
  Matrix<T> B11 = B.get11();
  Matrix<T> B12 = B.get12();
  Matrix<T> B21 = B.get21();
  Matrix<T> B22 = B.get22();

  Matrix<T> S1 = B12 - B22;
  Matrix<T> S2 = A11 + A12;
  Matrix<T> S3 = A21 + A22;
  Matrix<T> S4 = B21 - B11;
  Matrix<T> S5 = A11 + A22;
  Matrix<T> S6 = B11 + B22;
  Matrix<T> S7 = A12 - A22;
  Matrix<T> S8 = B21 + B22;
  Matrix<T> S9 = A11 - A21;
  Matrix<T> S10 = B11 + B12;

  Matrix<T> P1 = strassen(A11, S1);
  Matrix<T> P2 = strassen(S2, B22);
  Matrix<T> P3 = strassen(S3, B11);
  Matrix<T> P4 = strassen(A22, S4);
  Matrix<T> P5 = strassen(S5, S6);
  Matrix<T> P6 = strassen(S7, S8);
  Matrix<T> P7 = strassen(S9, S10);

  Matrix<T> C11 = P5 + P4 - P2 + P6;
  Matrix<T> C12 = P1 + P2;
  Matrix<T> C21 = P3 + P4;
  Matrix<T> C22 = P5 + P1 - P3 - P7;

  C = combine(C11, C12, C21, C22);

  return C;
}
}  // namespace CH4
}  // namespace CLRS

#endif