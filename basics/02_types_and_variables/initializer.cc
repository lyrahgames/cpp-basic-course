#include <iostream>

int main() {
  float x{1.5};
  int a{x};
  int b = x;
  int c = {x};
  int d(x);

  std::cout << "x = " << x << std::endl
            << "a = " << a << std::endl
            << "b = " << b << std::endl
            << "c = " << c << std::endl
            << "d = " << d << std::endl;
}