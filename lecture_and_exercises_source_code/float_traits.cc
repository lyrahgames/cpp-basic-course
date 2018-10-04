#include <iostream>

int main() {
  float x = 10.5f;
  float y = 1.2e-2f;
  std::cout << "x = " << x << "\ny = " << y << std::endl;
  float a = x + y;
  std::cout << "a = " << a << std::endl;
  float b = x - y;
  std::cout << "b = " << b << std::endl;
  float c = x * y;
  std::cout << "c = " << c << std::endl;
  float d = x / y;
  std::cout << "d = " << d << std::endl;
  // float e = x % y;
  // std::cout << "e = " << e << std::endl;
}