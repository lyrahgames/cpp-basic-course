#include <iostream>

#include <rational.h>

int main() {
  Rational a;
  std::cout << "a = " << a << std::endl;
  Rational x{1, 2};
  // x.denominator = 2;
  // x.numerator = 1;
  Rational y{2, 4};
  // y.denominator = 4;
  // y.numerator = 3;
  // Rational z = multiply(x, y);
  Rational z = x * y;
  // z.denominator = x.denominator * y.denominator;
  // z.numerator = x.numerator * y.numerator;

  // std::cout << "result = " << z.numerator << "/" << z.denominator <<
  // std::endl;
  std::cout << "result = " << z << std::endl
            << "z * 2 = " << z * 2 << std::endl
            << "result = " << static_cast<double>(z) << std::endl
            << "result = " << double{z} << std::endl;

  if (x == y) {
    std::cout << "x is equal to y\n";
  } else {
    std::cout << "x is not equal to y\n";
  }
}