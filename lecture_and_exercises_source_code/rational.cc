#include "rational.h"

Rational multiply(Rational x, Rational y) {
  return {x.numerator * y.numerator, x.denominator * y.denominator};
}

Rational operator*(Rational x, Rational y) { return multiply(x, y); }

std::ostream& operator<<(std::ostream& os, Rational x) {
  return os << x.numerator << "/" << x.denominator;
  // return os;
}