#include <iostream>

float exp(float x, int n);

int main() {
  std::cout << "Give me a real value and a natural number:\n";
  int n;
  float x;
  std::cin >> x >> n;

  std::cout << "exp(x,n) = " << exp(x, n) << std::endl;
}

float exp(float x, int n) {
  float result = 1.0f;
  float tmp = 1.0f;
  for (int i = 1; i <= n; ++i) {
    tmp *= x / i;
    result += tmp;
  }
  return result;
}