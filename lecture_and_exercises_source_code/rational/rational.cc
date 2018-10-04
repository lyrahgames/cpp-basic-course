#include "rational.h"

Rational::Rational(int numerator_in, int denominator_in)
    : numerator_{numerator_in}, denominator_{denominator_in} {
  if (denominator_ == 0) {
    denominator_ = 1;
    std::cout << "Warning: Denominator must not be zero! Set to 1!\n";
  }
}

void Rational::set_denominator(int denominator_in) {
  if (denominator_in == 0) {
    std::cout << "Warning: Denominator must not be zero!\n";
    return;
  }

  denominator_ = denominator_in;
}

Rational multiply(Rational x, Rational y) {
  return {x.numerator() * y.numerator(), x.denominator() * y.denominator()};
}

Rational operator*(Rational x, Rational y) { return multiply(x, y); }

// Rational operator*(Rational x, int n) {
//   // return {x.numerator * n, x.denominator};
//   return x * Rational{n, 1};
// }

// Rational operator*(int n, Rational x) { return x * n; }

Rational operator-(Rational x, Rational y) {
  return {x.numerator() * y.denominator() - y.numerator() * x.denominator(),
          x.denominator() * y.denominator()};
}

// bool operator==(Rational x, Rational y) { return (x - y).numerator() == 0; }
bool operator==(Rational x, Rational y) {
  return x.numerator() * y.denominator() - y.numerator() * x.denominator() == 0;
}

bool operator!=(Rational x, Rational y) { return !(x == y); }

std::ostream& operator<<(std::ostream& os, Rational x) {
  return os << x.numerator() << "/" << x.denominator();
  // return os;
}