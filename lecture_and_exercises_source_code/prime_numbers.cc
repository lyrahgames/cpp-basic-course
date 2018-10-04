#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

void compute_prime_numbers(int count, std::vector<int>& data) {
  std::vector<bool> is_prime_number(count, true);
  is_prime_number[0] = is_prime_number[1] = false;

  for (int i = 2; i <= std::sqrt(count); i++) {
    if (!is_prime_number[i]) continue;
    for (int j = 2 * i; j < count; j += i) {
      is_prime_number[j] = false;
    }
  }

  for (int i = 0; i < count; ++i) {
    if (is_prime_number[i]) data.push_back(i);
  }
}

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <upper bound>\n";
    return -1;
  }

  int count;
  std::stringstream input{argv[1]};
  input >> count;

  std::vector<int> prime_numbers;
  compute_prime_numbers(count, prime_numbers);

  for (int i = 0; i < prime_numbers.size(); ++i) {
    std::cout << prime_numbers[i] << '\t';
  }
  // for (int i = 0; i < count; ++i) {
  //   if (is_prime_number[i]) std::cout << i << '\t';
  // }
  std::cout << std::endl;
}