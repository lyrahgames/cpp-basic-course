#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <upper bound>\n";
    return -1;
  }

  int count;
  std::stringstream input{argv[1]};
  input >> count;

  std::vector<bool> is_prime_number(count, true);
  is_prime_number[0] = is_prime_number[1] = false;

  for (int i = 2; i <= std::sqrt(count); i++) {
    if (!is_prime_number[i]) continue;
    for (int j = 2 * i; j < count; j += i) {
      is_prime_number[j] = false;
    }
  }

  for (int i = 0; i < count; ++i) {
    if (is_prime_number[i]) std::cout << i << '\t';
  }
  std::cout << std::endl;
}