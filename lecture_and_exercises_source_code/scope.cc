#include <iostream>

int main() {
  int x = 1;
  int y = 10;
  {
    int x = 2;
    {
      int x = 3;
      std::cout << x << std::endl;
      std::cout << y << std::endl;
    }
    std::cout << x << std::endl;
  }
  std::cout << x << std::endl;
}