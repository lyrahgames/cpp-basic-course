#include <iostream>
#include <vector>

int main() {
  std::vector<int> x(10, 0);
  for (int i = 0; i < 10; ++i) {
    x[i] = i * i;
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << x[i] << std::endl;
  }
}