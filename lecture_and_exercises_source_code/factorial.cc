#include <iostream>

int main() {
  int n;
  std::cin >> n;

  double factorial = 1.0;
  for (int i = 2; i <= n; ++i) {
    factorial *= i;
    std::cout << i << ":\t" << factorial << std::endl;
  }
}