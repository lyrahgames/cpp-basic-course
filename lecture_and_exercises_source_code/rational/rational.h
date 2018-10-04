#ifndef RATIONAL_RATIONAL_H_
#define RATIONAL_RATIONAL_H_

#include <iostream>

class Rational {
 public:
  Rational() : numerator_{0}, denominator_{1} {}
  Rational(int n) : numerator_{n}, denominator_{1} {}
  Rational(int numerator_in, int denominator_in);

  explicit operator double() {
    return static_cast<double>(numerator_) / denominator_;
  }

  int numerator() { return numerator_; }
  void set_numerator(int numerator_in) { numerator_ = numerator_in; }
  int denominator() { return denominator_; }
  void set_denominator(int denominator_in);

 private:
  int numerator_;
  int denominator_;
};

Rational multiply(Rational x, Rational y);
Rational operator*(Rational x, Rational y);
// Rational operator*(Rational x, int n);
// Rational operator*(int n, Rational x);
Rational operator-(Rational x, Rational y);
bool operator==(Rational x, Rational y);
bool operator!=(Rational x, Rational y);
std::ostream& operator<<(std::ostream& os, Rational x);

#endif  // RATIONAL_RATIONAL_H_