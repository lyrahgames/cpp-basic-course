#include <iostream>

int square(int x);

int main() {
  std::cout << "Give me an integral number:\n";
  int x;
  std::cin >> x;

  std::cout << "square(" << x << ") = " << square(x) << std::endl;
}

int square(int x) { return x * x; }