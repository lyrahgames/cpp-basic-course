#include <iostream>

int main() {
  for (char c = 'a'; c <= 'z'; ++c) {
    std::cout << c << ":\t" << static_cast<int>(c) << std::endl;
  }
}