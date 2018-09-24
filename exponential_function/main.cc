#include <cmath>
#include <iostream>

int main() {
  std::cout << "Give me a real value and a natural number:\n";
  int n;
  float x;
  std::cin >> x >> n;

  float result = 1.0f;
  float tmp = 1.0f;
  for (int i = 1; i <= n; ++i) {
    tmp *= x / i;
    result += tmp;
  }

  std::cout << "std::exp(x) = " << std::exp(x) << std::endl
            << "taylor = " << result << std::endl
            << "deviation = " << std::abs(result - std::exp(x)) << std::endl;
}