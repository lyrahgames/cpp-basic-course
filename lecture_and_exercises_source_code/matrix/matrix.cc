#include "matrix.h"

#include <cassert>

namespace Math {

Matrix operator*(Matrix m, Matrix n) {
  // Matrix operator*(const Matrix& m, const Matrix& n) {
  assert(m.dimension() == n.dimension());
  Matrix result{m.dimension(), 0.0f};
  for (int i = 0; i < result.dimension(); ++i) {
    for (int j = 0; j < result.dimension(); ++j) {
      for (int k = 0; k < result.dimension(); ++k) {
        result(i, j) += m(i, k) * n(k, j);
      }
    }
  }
  return result;
}

Matrix operator+(Matrix m, Matrix n) {
  // Matrix operator+(const Matrix& m, const Matrix& n) {
  assert(m.dimension() == n.dimension());
  Matrix result{m.dimension(), 0.0f};
  for (int i = 0; i < result.dimension(); ++i) {
    for (int j = 0; j < result.dimension(); ++j) {
      result(i, j) = m(i, j) + n(i, j);
    }
  }
  return result;
}

}  // namespace Math

std::ostream& operator<<(std::ostream& os, const Math::Matrix& m) {
  for (int i = 0; i < m.dimension(); ++i) {
    for (int j = 0; j < m.dimension(); ++j) {
      os << m(i, j) << "\t";
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Math::Matrix& m) {
  for (int i = 0; i < m.dimension(); ++i) {
    for (int j = 0; j < m.dimension(); ++j) {
      is >> m(i, j);
    }
  }
  return is;
}