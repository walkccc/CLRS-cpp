#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  allocateMemories();
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
    : rows(matrix.rows), cols(matrix.cols) {
  allocateMemories();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      p[i][j] = matrix.p[i][j];
    }
  }
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& vec)
    : rows(vec.size()), cols(vec[0].size()) {
  allocateMemories();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      p[i][j] = vec[i][j];
    }
  }
}

template <typename T>
Matrix<T> Matrix<T>::get11() const {
  Matrix m(rows / 2, cols / 2);
  for (int i = 0; i < rows / 2; i++) {
    for (int j = 0; j < cols / 2; j++) {
      m.p[i][j] = p[i][j];
    }
  }
  return m;
}

template <typename T>
Matrix<T> Matrix<T>::get12() const {
  Matrix m(rows / 2, cols - cols / 2);
  for (int i = 0; i < rows / 2; i++) {
    for (int j = 0; j < cols - cols / 2; j++) {
      m.p[i][j] = p[i][j + cols / 2];
    }
  }
  return m;
}

template <typename T>
Matrix<T> Matrix<T>::get21() const {
  Matrix m(rows - rows / 2, cols / 2);
  for (int i = 0; i < rows - rows / 2; i++) {
    for (int j = 0; j < cols / 2; j++) {
      m.p[i][j] = p[i + rows / 2][j];
    }
  }
  return m;
}

template <typename T>
Matrix<T> Matrix<T>::get22() const {
  Matrix m(rows - rows / 2, cols - cols / 2);
  for (int i = 0; i < rows - rows / 2; i++) {
    for (int j = 0; j < cols - cols / 2; j++) {
      m.p[i][j] = p[i + rows / 2][j + cols / 2];
    }
  }
  return m;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
  Matrix<T> res(lhs);
  for (int i = 0; i < res.rows; i++) {
    for (int j = 0; j < res.cols; j++) {
      res.p[i][j] += rhs.p[i][j];
    }
  }
  return res;
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
  Matrix<T> res(lhs);
  for (int i = 0; i < res.rows; i++) {
    for (int j = 0; j < res.cols; j++) {
      res.p[i][j] -= rhs.p[i][j];
    }
  }
  return res;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
  Matrix<T> res(lhs.rows, rhs.cols);
  for (int i = 0; i < res.rows; i++) {
    for (int j = 0; j < res.cols; j++) {
      for (int k = 0; k < res.rows; k++) {
        res.p[i][j] += lhs.p[i][k] * rhs.p[k][j];
      }
    }
  }
  return res;
}

template <typename T>
Matrix<T> combine(const Matrix<T>& m11, const Matrix<T>& m12,
                  const Matrix<T>& m21, const Matrix<T>& m22) {
  int m = m11.rows + m21.rows;
  int n = m11.cols + m12.cols;

  Matrix<T> matrix(m, n);

  int y = m / 2;
  int x = n / 2;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++)
      matrix.p[i][j] = m11.p[i][j];
    for (int j = 0; j < n - x; j++)
      matrix.p[i][j + x] = m12.p[i][j];
  }

  for (int i = 0; i < m - y; i++) {
    for (int j = 0; j < x; j++)
      matrix.p[i + y][j] = m21.p[i][j];
    for (int j = 0; j < x; j++)
      matrix.p[i + y][j + x] = m22.p[i][j];
  }

  return matrix;
}

template <typename T>
void Matrix<T>::allocateMemories() {
  p = new T*[rows];
  for (int i = 0; i < rows; i++) {
    p[i] = new T[cols];
    for (int j = 0; j < cols; ++j)
      p[i][j] = 0;
  }
}