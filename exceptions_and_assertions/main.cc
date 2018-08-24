#include <iostream>
#include <stdexcept>

int gauss_sum(int n) {
  if (n < 0)
    throw std::invalid_argument(
        "The argument of 'gauss_sum' has to be non-negative!");

  return n * (n + 1) / 2;
}

int main() {
  try {
    std::cout << gauss_sum(-1) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << gauss_sum(10) << std::endl;
  std::cout << gauss_sum(-2) << std::endl;
}