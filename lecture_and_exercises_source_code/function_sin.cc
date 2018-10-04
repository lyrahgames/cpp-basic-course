#include <iostream>

float sin(float x);

int main() {
  float x;
  std::cin >> x;

  std::cout << "sin(x) = " << sin(x) << std::endl;
}

float sin(float x) {
  const int n = 20;
  float result = x;
  float tmp = x;
  for (int i = 3; i <= n; i += 2) {
    tmp *= -1.0 * x * x / (i * (i - 1));
    result += tmp;
  }
  return result;
}