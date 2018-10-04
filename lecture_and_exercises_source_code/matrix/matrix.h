#ifndef MATRIX_MATRIX_H_
#define MATRIX_MATRIX_H_

#include <iostream>
#include <vector>

namespace Math {

class Matrix {
 public:
  Matrix() : dimension_{0}, elements_{} {}
  Matrix(int dimension, float value)
      : dimension_{dimension}, elements_(dimension * dimension, value) {}

  float& operator()(int i, int j) { return elements_[i * dimension_ + j]; }

  const float& operator()(int i, int j) const {
    return elements_[i * dimension_ + j];
  }
  int dimension() const { return dimension_; }

 private:
  int dimension_;
  std::vector<float> elements_;
};

Matrix operator*(Matrix m, Matrix n);
// Matrix operator*(const Matrix& m, const Matrix& n);

Matrix operator+(Matrix m, Matrix n);
// Matrix operator+(const Matrix& m, const Matrix& n);

}  // namespace Math

std::ostream& operator<<(std::ostream& os, const Math::Matrix& m);
std::istream& operator>>(std::istream& is, Math::Matrix& m);

#endif  //  MATRIX_MATRIX_H_