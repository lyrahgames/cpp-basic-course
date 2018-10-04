#include <iostream>

int main() {
  double x = 10.5;
  double y = 1.2e-2;
  std::cout << "x = " << x << "\ny = " << y << std::endl;
  double a = x + y;
  std::cout << "a = " << a << std::endl;
  double b = x - y;
  std::cout << "b = " << b << std::endl;
  double c = x * y;
  std::cout << "c = " << c << std::endl;
  double d = x / y;
  std::cout << "d = " << d << std::endl;
}