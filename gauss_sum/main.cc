#include <iostream>

int main() {
  std::cout << "Give me a positive number:\n";
  int n;
  std::cin >> n;

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int test = i * (i + 1) / 2;
    sum += i;

    std::cout << "test = " << test << "\tsum = " << sum;
    if (sum != test) std::cout << "Gauss was wrong...";
    std::cout << std::endl;
  }
}