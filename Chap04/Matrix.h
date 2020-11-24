#ifndef Matrix_h
#define Matrix_h

#include <iostream>

template <typename T>
class Matrix {
  T** p;
  int rows;
  int cols;
  void allocateMemories();

 public:
  Matrix<T>(int, int);
  Matrix<T>(const Matrix<T>&);
  Matrix<T>(const std::vector<std::vector<T>>&);

  Matrix<T> get11() const;
  Matrix<T> get12() const;
  Matrix<T> get21() const;
  Matrix<T> get22() const;

  int getRows() const {
    return rows;
  }

  int getCols() const {
    return cols;
  }

  T** getP() const {
    return p;
  }

  inline T& operator()(int x, int y) {
    return p[x][y];
  }

  template <class U>
  friend Matrix<U> operator+(const Matrix<U>& lhs, const Matrix<U>& rhs);

  template <class U>
  friend Matrix<U> operator-(const Matrix<U>& lhs, const Matrix<U>& rhs);

  template <class U>
  friend Matrix<U> operator*(const Matrix<U>& lhs, const Matrix<U>& rhs);

  template <class U>
  friend Matrix<U> combine(const Matrix<U>& m11, const Matrix<U>& m12,
                           const Matrix<U>& m21, const Matrix<U>& m22);

  friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
      for (int j = 0; j < matrix.cols; j++) {
        os << matrix.p[i][j] << " ";
      }
      os << std::endl;
    }
    return os;
  }
};

#endif