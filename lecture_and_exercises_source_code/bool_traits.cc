#include <iostream>

int main() {
  int a = 3;
  int b = 4;
  bool x = a <= b;
  std::cout << "x = " << x << std::endl;
  bool y = a == b;
  bool z = a != b;
  std::cout << "y = " << y << std::endl;
  bool x_and_y = x && y;
  std::cout << "x_and_y = " << x_and_y << std::endl;
  bool x_or_y = x || y;
  std::cout << "x_or_y = " << x_or_y << std::endl;
  bool x_not = !x;
  std::cout << "!x = " << !x << std::endl;
}