#include <cassert>
#include <iostream>

int fibonacci(int n) {
  assert(n >= 0);
  if (n <= 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  for (int i = -1; i < 20; ++i)
    std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << std::endl;
}